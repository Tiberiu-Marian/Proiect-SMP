334AB
Manolescu Costin
Mihalea Tiberiu Marian
Acest proiect presupune transmiterea unui mesaj in cod morse de la un emitator la un receptor. Au fost folosite doua placi Arduino, doua
Breadboard-uri, cabluri si o pereche emitator receptor RF.
Componenta de transmisie a fost realizata conectand la Arduino cei trei pini ai emitatorului RF. Pinii au fost conectati la baza, la 
pinul 12 si la pinul 5V. 
Este utilizata biblioteca RadioHead. 

Functii
Emitator:
1. setup 
2. convert - contine un loop care imparte mesajul scris in litere si le codifica printr-un switch
3. loop - citeste mesajul din serial, il converteste in morse si il trimite prin metodele obiectului "driver" 
Receptor:
1.setup
2. convert - contine un loop care traduce codul morse intr-un mesaj (litere minuscule)
3. loop - primeste mesajul de la emitator, il decodeaza si il afiseaza