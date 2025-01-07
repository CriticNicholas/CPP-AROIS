import socket
import threading
import time
import random

# Параметры сервера
HOST = '127.0.0.1'
PORT = 65432

# Эмуляция данных от импланта
def generate_signal():
    signals = ["Pulse: 75 bpm", "Temp: 36.6 C", "Signal Strength: 90%", "Battery: 80%"]
    return random.choice(signals)

# Функция обработки клиента
def handle_client(conn, addr):
    print(f"[+] Подключен клиент: {addr}")
    try:
        while True:
            # Эмуляция отправки данных от импланта
            signal = generate_signal()
            conn.sendall(signal.encode())
            time.sleep(1)  # Отправка данных каждую секунду

            # Получение команды от клиента
            command = conn.recv(1024).decode()
            if command == "shutdown":
                print(f"[-] Клиент {addr} отключен")
                break
            print(f"[!] Команда получена: {command}")

            # Ответ на команду
            conn.sendall(b"Acknowledged")
    except Exception as e:
        print(f"[!] Ошибка: {e}")
    finally:
        conn.close()

# Запуск сервера
def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"[*] Сервер запущен на {HOST}:{PORT}")

    while True:
        conn, addr = server_socket.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[!] Активные соединения: {threading.active_count() - 1}")

start_server()

