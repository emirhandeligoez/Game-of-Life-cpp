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
<img width="975" height="674" alt="{05498D9B-A787-435B-9DE4-300374557C79}" src="https://github.com/user-attachments/assets/f7934245-e810-4cdc-b631-de03fe0c688f" />
