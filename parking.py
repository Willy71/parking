import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QTextEdit, QButtonGroup, QMessageBox, QDesktopWidget
from PyQt5.uic import loadUi
from PyQt5.QtGui import QColor, QTextDocument, QTextCursor
import pandas as pd
from datetime import datetime, timedelta
from PyQt5.QtPrintSupport import QPrinter, QPrintDialog
import os


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Carga la interfaz desde el archivo .ui
        loadUi("C:\PythonProjects\Programas para vender\Estacionamiento\parking.ui", self)
        # Crear grupo de botones
        self.button_group = QButtonGroup()
        self.button_group.addButton(self.ingreso)
        self.button_group.addButton(self.saida)

        # Asignar instancias de widgets a los atributos de la clase
        self.outro_carro = self.findChild(QTextEdit, 'outro_carro')

        # Conectar la señal clicked del botón a la función correspondiente
        self.form_submit_button.clicked.connect(self.funcion_entrada)
        self.form_submit_button.clicked.connect(self.funcion_saida)
        self.form_submit_button.clicked.connect(self.clear_content)
        # Agrega esto en el constructor de la clase MainWindow, después de conectar otros eventos
        self.Button_imprimir.clicked.connect(self.imprimir_datos)

        # Inicializar la visibilidad de los widgets
        self.outro_carro.hide()
        self.label_outro.hide()
        self.carro.show()
        self.label_carro.show()

        # Hace que comience el boton entrada en violeta y seleccionado
        self.on_ingreso_clicked()
        # Establecer el radioButton "entrada" como seleccionado
        self.ingreso.setChecked(True)

        # Inicializar la variable carro
        self.hora_saida = None
        self.user_id = None
        self.carro_seleccionado = None
        self.duracion_en_minutos = ''
        self.custo = 0

        # Conectar la señal clicked de los botones a funciones correspondientes
        self.ingreso.clicked.connect(self.on_ingreso_clicked)
        self.saida.clicked.connect(self.on_saida_clicked)

        # Conectar la señal de cambio de selección en el QComboBox *carro
        self.carro.currentIndexChanged.connect(self.on_carro_selection_changed)

        # Conectar el evento textChanged a la función correspondiente
        self.placa.textChanged.connect(self.placa_limite)

        # Cargar la lista de carros
        self.cargar_lista_carros()

      # Configura la interfaz de usuario y otras configuraciones
        self.setWindowTitle('Estacionamento')
        self.setGeometry(100, 100, 900, 650)  # Tamaño inicial, puede cambiar

        # Centra la ventana en la pantalla
        self.centra_en_pantalla()

    def centra_en_pantalla(self):
        # Obtiene la geometría de la pantalla principal
        pantalla_principal = QDesktopWidget().screenGeometry()

        # Calcula las coordenadas para centrar la ventana
        x = int((pantalla_principal.width() - self.width()) / 2)
        y = int((pantalla_principal.height() - self.height()) / 2)

        # Establece la posición de la ventana
        self.move(x, y)

    def funcion_entrada(self):
        global hora_entrada
        # Guarda el contenido del QPlainTextEdit en una variable diferente
        texto_placa = self.placa.toPlainText().upper()

        # Verifica si el radio button "Entrada" está seleccionado
        if self.ingreso.isChecked():
            if len(texto_placa) != 7:
                self.mostrar_advertencia(
                    "A placa deve ter exatamente 7 caracteres.")
                return
            elif self.carro.currentText() == "" or (self.carro.currentText() == "Outro" and self.outro_carro.toPlainText().strip() == ""):
                self.mostrar_advertencia("Os campos são obrigatórios.")
                return
            else:
                # Establecer el texto en el QLabel label_info_placa
                self.label_info_placa.setText("Placa: " + texto_placa)
                # Obtener el carro seleccionado en el ComboBox
                if self.carro.currentText() == "Outro":
                    carro_seleccionado = self.outro_carro.toPlainText()
                else:
                    carro_seleccionado = self.carro.currentText()
                # Mostrar el carro seleccionado en el QLabel label_info_carro
                self.label_info_carro.setText("Carro: " + carro_seleccionado)
                # Actualizar la variable carro_texto con la selección
                self.carro_texto = carro_seleccionado
                # Obtener la hora y fecha de entrada
                hora_entrada = datetime.now().strftime("%H:%M %d/%m/%Y")
                # Mostrar la hora y fecha de entrada en el QLabel label_info_entrada
                self.label_info_entrada.setText("Entrada: " + hora_entrada)
                # Asignar el contenido al QPlainTextEdit después de mostrar la información
                self.placa.setPlainText(texto_placa)
                # Guardar los datos en el archivo CSV
                self.guardar_entrada()
                self.clear_content()

    def funcion_saida(self):
        global user_id, hora_saida, custo

        texto_placa = self.placa.toPlainText().strip().upper()

        if self.saida.isChecked():
            if len(texto_placa) != 7:
                self.mostrar_advertencia(
                    "A placa deve ter exatamente 7 caracteres.")
                return
            else:
                # Intenta cargar el DataFrame desde el archivo CSV
                df = self.leer_dataframe(pd.DataFrame())

                # Buscar la fila correspondiente en el DataFrame
                user = df[df["Placa"] == texto_placa].sort_values(
                    by="user_id", ascending=False).head(1)

                if not user.empty:
                    self.hora_saida = datetime.now().strftime("%H:%M %d/%m/%Y")
                    self.user_id = user["user_id"].values[0]
                    self.hora_entrada = user['Hora de entrada'].values[0]
                    self.carro_seleccionado = user['Carro'].values[0]
                    self.label_info_placa.setText("Placa: " + texto_placa)
                    self.label_info_carro.setText(
                        "Carro: " + self.carro_seleccionado)
                    self.label_info_entrada.setText(
                        "Entrada: " + self.hora_entrada)
                    self.label_info_saida.setText("Saída: " + self.hora_saida)
                    # Llamada a calcular_tiempo y actualización de self.duracion_en_minutos
                    self.duracion_en_minutos = MainWindow.calcular_tiempo(
                        self.hora_entrada, self.hora_saida)
                    # Calcular la duración directamente aquí
                    duracion = self.calcular_tiempo(
                        self.hora_entrada, self.hora_saida)
                    horas, minutos = divmod(int(duracion), 60)
                    duracion_formateada = f"{horas} hs e {minutos} minutos"
                    self.label_info_tempo.setText(
                        "Tempo total: " + duracion_formateada)
                    self.custo = MainWindow.calcular_costo()
                    self.label_info_custo.setText(
                        "Custo: R$ " + str(self.custo))
                    self.guardar_salida(self.hora_saida, self.user_id)
                else:
                    # Mostrar ventana emergente
                    mensaje = "Placa não encontrada no banco de dados."
                    QMessageBox.critical(self, "Erro", mensaje)

    @staticmethod
    def calcular_tiempo(hora_entrada, hora_saida):
        global duracion_en_minutos
        formato = "%H:%M %d/%m/%Y"

        # Convertir las cadenas de tiempo a objetos datetime
        entrada = datetime.strptime(hora_entrada, formato)
        saida = datetime.strptime(hora_saida, formato)

        # Calcular la duración
        duracion = saida - entrada

        # Convertir la duración a minutos y luego a cadena (str)
        duracion_int = int(duracion.total_seconds() / 60)
        duracion_en_minutos = int(duracion_int)

        return duracion_en_minutos

    @staticmethod
    def calcular_costo():
        global duracion_en_minutos
        valor_hora = 6
        minutos_tolerancia = 5
        # Aplicar la tolerancia después de calcular las medias horas
        duracion_en_minutos -= minutos_tolerancia
        # Calcular las medias horas antes de restar la tolerancia
        # Ajuste para redondear hacia arriba
        medias_horas = int((duracion_en_minutos + 29) / 30)
        # Calcular el costo con la tolerancia de 5 minutos
        custo = round(medias_horas * (valor_hora / 2), 2)
        return custo

    def on_ingreso_clicked(self):
        # Lógica para el botón de Entrada
        self.outro_carro.hide()
        self.carro.show()
        self.label_carro.show()
        self.label_outro.hide()

        self.ingreso.setStyleSheet("background-color: lightblue")
        self.saida.setStyleSheet("background-color: transparent")

        # Limpiar los QLabel
        self.limpiar_datos_labels()

    def on_saida_clicked(self):
        # Lógica para el botón de Salida
        self.outro_carro.hide()
        self.carro.hide()
        self.label_carro.hide()
        self.label_outro.hide()

        self.saida.setStyleSheet("background-color: lightblue")
        self.ingreso.setStyleSheet("background-color: transparent")

        # Limpiar los QLabel
        self.limpiar_datos_labels()

    def clear_content(self):
        self.placa.clear()
        self.carro.setCurrentIndex(-1)
        self.outro_carro.clear()

    def limpiar_datos_labels(self):
        # Restablecer el texto original en los QLabel
        self.label_info_placa.setText("Placa:")
        self.label_info_carro.setText("Carro:")
        self.label_info_entrada.setText("Entrada:")
        self.label_info_saida.setText("Saída:")
        self.label_info_tempo.setText("Tempo total:")
        self.label_info_custo.setText("Custo:")

    def on_carro_selection_changed(self, index):
        # Mostrar QTextEdit *outro_carro cuando se selecciona "Outro" en el ComboBox
        self.outro_carro.setVisible(self.carro.currentText() == "Outro")
        self.label_outro.setVisible(self.carro.currentText() == "Outro")

    def placa_limite(self):
        # Obtener el texto actual del QTextEdit
        current_text = self.placa.toPlainText()

        # Verificar si el texto supera el límite de 7 caracteres alfanuméricos
        if len(current_text) > 7:
            # Si excede el límite, truncar el texto y actualizar el QTextEdit
            new_text = current_text[:7]
            self.placa.setPlainText(new_text)

            # Mover el cursor al final del texto
            cursor = self.placa.textCursor()
            cursor.movePosition(cursor.End)
            self.placa.setTextCursor(cursor)

    def guardar_entrada(self):
        # Generar un ID único y secuencial (puedes ajustar esto según tus necesidades)
        user_id = self.generar_user_id()

        # Crear un diccionario con los datos a guardar
        datos = {
            "user_id": int(user_id),
            "Placa": str(self.placa.toPlainText().upper()),
            "Carro": str(self.carro_texto),
            "Hora de entrada": hora_entrada,
            "Hora de saida": "",  # Inicializar la columna "Hora de saida" con un string vacío
            "Quantidade de horas": "",
            "Custo": ""
        }

        # Crear un DataFrame con los nuevos datos
        df_nuevo = pd.DataFrame([datos])

        # Intentar cargar el archivo CSV existente o crear uno nuevo si no existe
        try:
            df_existente = pd.read_csv(
                "C:\PythonProjects\Programas para vender\Estacionamiento\database.csv")
            df_actualizado = pd.concat(
                [df_existente, df_nuevo], ignore_index=True)
        except FileNotFoundError:
            df_actualizado = df_nuevo

        # Guardar el DataFrame actualizado en el archivo CSV
        df_actualizado.to_csv(
            "C:\PythonProjects\Programas para vender\Estacionamiento\database.csv", index=False)

    def guardar_salida(self, hora_saida, user_id):
        global hora_entrada, duracion_en_minutos, custo
        df = self.leer_dataframe(pd.DataFrame())
        # Eliminar la entrada anterior solo si existe
        if user_id in df['user_id'].values:
            df = df[df['user_id'] != user_id]

            # Crear un diccionario con los datos a guardar
            datos_2 = {
                "user_id": int(user_id),
                "Placa": str(self.placa.toPlainText().upper()),
                "Carro": str(self.carro_seleccionado),
                "Hora de entrada": self.hora_entrada,
                "Hora de saida": hora_saida,
                "Quantidade de horas": self.duracion_en_minutos,
                "Custo": self.custo
            }
            # Convertir el diccionario en un DataFrame
            df_nuevo = pd.DataFrame([datos_2])
            # Agregar la nueva entrada al DataFrame
            df = pd.concat([df, df_nuevo], ignore_index=True)
            # Ordenar el DataFrame por user_id
            df.sort_values(by='user_id', inplace=True)
            # Restablecer el índice
            df.reset_index(drop=True, inplace=True)

            # Guardar el DataFrame actualizado en el archivo CSV
            df.to_csv(
                "C:\PythonProjects\Programas para vender\Estacionamiento\database.csv", index=False)
        # else:
            # warning("Entrada correspondente não encontrada.")

    def leer_dataframe(self, df):
        file_name = 'database.csv'
        file_dir = os.path.dirname(os.path.abspath(__file__))
        filepath = os.path.join(file_dir, file_name)
        # Leer el DataFrame desde el archivo CSV si existe
        if os.path.exists(filepath):
            # Leer el DataFrame desde el archivo CSV usando punto y coma como delimitador
            df = pd.read_csv(filepath, delimiter=',', dtype={'Carro': str})
            # Convertir 'user_id' a tipo entero, pero solo para valores numéricos
            df['user_id'] = pd.to_numeric(
                df['user_id'], errors='coerce', downcast='integer')
            # Eliminar filas con 'user_id' no numéricos (NaN)
            df = df.dropna(subset=['user_id'])
            # Convertir 'user_id' a tipo entero (si no ha sido eliminado completamente)
            df['user_id'] = df['user_id'].astype('Int64')
        else:
            # Crear un DataFrame vacío si el archivo no existe
            df = pd.DataFrame(columns=['user_id', 'Placa', 'Carro', 'Hora de entrada',
                                       'Hora de saida', 'Quantidade de horas', 'Custo'])
        return df

    def generar_user_id(df):
        df = pd.read_csv(
            "C:\PythonProjects\Programas para vender\Estacionamiento\database.csv")
        if df.empty:
            return 1
        else:
            return df['user_id'].max() + 1

    def cargar_lista_carros(self):
        # Leer la base de datos y obtener la lista de carros
        carros_df = pd.read_csv(
            "C:\PythonProjects\Programas para vender\Estacionamiento\carros_sort.csv")
        opciones_carros = carros_df["Carro"].tolist()
        # Limpiar el contenido actual del ComboBox
        self.carro.clear()
        # Agregar las opciones al ComboBox
        self.carro.addItems(opciones_carros)

    def mostrar_advertencia(self, mensaje):
        QMessageBox.warning(self, "Aviso", mensaje)

    def imprimir_datos(self):
        printer = QPrinter()
        dialog = QPrintDialog(printer, self)

        if dialog.exec_() != QPrintDialog.Accepted:
            return

        # Crear un objeto QTextDocument con el contenido de los labels
        document = QTextDocument()

        # Crear un cursor para insertar texto en el documento
        cursor = QTextCursor(document)

        # Insertar el contenido común de los labels en el documento
        cursor.insertText(self.label_info_placa.text() + "\n")
        cursor.insertText(self.label_info_carro.text() + "\n")
        cursor.insertText(self.label_info_entrada.text() + "\n")

        # Insertar elementos adicionales si la salida está seleccionada
        if self.saida.isChecked():
            cursor.insertText(self.label_info_saida.text() + "\n")
            cursor.insertText(self.label_info_tempo.text() + "\n")
            cursor.insertText(self.label_info_custo.text())

        # Imprimir el documento
        document.print_(printer)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
