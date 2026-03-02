# Übung 3: Framework-Abgleich

**Ziel:** Nehmen Sie ein konkretes Modul aus Ihrem Framework (z.B. eine Klasse aus dem Input Densply Sirona-Framework, die Sie kennen). Beantworten Sie dazu folgende Fragen:

1. **Polymorphie:**  
   - Enthält die Klasse virtuelle Funktionen?  
   - Falls ja: Wie viele Instanzen werden typischerweise erzeugt? (Abschätzung)  
   - Wie häufig werden die virtuellen Funktionen aufgerufen?  

2. **Speicherkosten:**  
   - Lässt sich die Größe der Objekte abschätzen? Wie viel Speicher geht durch vptr verloren?  

3. **SOLID-Konformität:**  
   - Hat die Klasse mehr als eine Verantwortung?  
   - Ist sie offen für Erweiterung, aber geschlossen für Modifikation?  
   - Verwendet sie Abhängigkeiten von Abstraktionen (DIP)?  

4. **Verbesserungspotenzial:**  
   - Welche der in dieser Session vorgestellten Alternativen (CRTP, Komposition, `variant`) könnten hier sinnvoll sein?  
   - Wo würden Sie mit der statischen Codeanalyse ansetzen?

Notieren Sie Ihre Antworten und diskutieren Sie sie im Team.
