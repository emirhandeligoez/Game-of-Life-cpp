# Game of Life (C++)

Dieses Programm ist eine Konsolenimplementierung von Game of Life. 
Dabei wird ein Spielfeld aus Zellen simuliert, die entweder leben oder tot sind und sich basierend auf festen Regeln weiterentwickeln.
Mit jedem Tastendruck wird die nächste Generation berechnet und angezeigt, bis das Programm beendet wird.

Für jede Zelle wird in jedem Schritt die Anzahl der lebenden Nachbarzellen berechnet. 
Eine lebende Zelle überlebt, wenn sie zwei oder drei lebende Nachbarn hat, andernfalls stirbt sie. 
Eine tote Zelle wird zu einer lebenden Zelle, wenn genau drei Nachbarn leben.

Das Programm durchläuft dabei das gesamte Spielfeld ähnlich wie ein Filter in der Bildverarbeitung und berechnet für jede Position den nächsten Zustand. 
Zusätzlich ist das Spielfeld als „wrap-around“ umgesetzt, wodurch die Ränder miteinander verbunden sind und ein endloses, durchlaufendes Feld entsteht.

Die Simulation wird schrittweise in der Konsole dargestellt und entwickelt sich mit jeder Eingabe weiter.

<img width="520" height="500" alt="{05498D9B-A787-435B-9DE4-300374557C79}" src="https://github.com/user-attachments/assets/f7934245-e810-4cdc-b631-de03fe0c688f" />

->

<img width="520" height="500" alt="{BD31F024-6DDC-4A1A-9E7C-5863D4483741}" src="https://github.com/user-attachments/assets/cbb3ddcb-e515-4fc8-8744-12c8761a331f" />

->

<img width="520" height="500" alt="{BA5D46D7-01CE-44BF-921C-9728FC6BF54F}" src="https://github.com/user-attachments/assets/9260bf9d-12a9-42e6-b875-d7713a7e58a7" />

