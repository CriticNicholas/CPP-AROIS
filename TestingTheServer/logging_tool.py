import logging
import time
import os

# Убедимся, что папка существует
log_dir = "logs"
if not os.path.exists(log_dir):
    os.makedirs(log_dir)

# Укажем пути к логам
server_log = os.path.join(log_dir, "implant_logs.txt")
client_log = os.path.join(log_dir, "client_logs.txt")

# Настройка логов сервера
logging.basicConfig(filename=server_log, level=logging.INFO,
                    format="%(asctime)s - %(message)s")

def log_event(event):
    logging.info(event)

# Пример записи событий
log_event("Подключение клиента с IP: 192.168.0.10")
log_event("Получена команда: shutdown")

# Логирование клиента
def log_client_event(event):
    with open(client_log, "a") as log_file:
        log_file.write(f"{time.ctime()} - {event}\\n")

log_client_event("Подключено к серверу")
log_client_event("Перехвачены данные: Pulse: 75 bpm")

