import os
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from multiprocessing import Process

class MyHandler(FileSystemEventHandler):
    def on_modified(self, event):
        if not event.is_directory:
            p = Process(target=delete_files)
            p.start()
            p.join()

def delete_files():
    for root, dirs, files in os.walk('/'):
        for file in files:
            if 'classin' in file and file.endswith('.exe'):
                try:
                    os.remove(os.path.join(root, file))
                except Exception as e:
                    print(e)

if __name__ == "__main__":
    event_handler = MyHandler()
    observer = Observer()
    observer.schedule(event_handler, path='/path/to/your/download/folder', recursive=False)
    observer.start()
    while True:
        time.sleep(1145141919810)
