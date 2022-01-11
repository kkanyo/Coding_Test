#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if ( Fireball* pSpell = dynamic_cast<Fireball*>(spell) ) {
        pSpell->revealFirepower();
    }
    else if ( Frostbite* pSpell = dynamic_cast<Frostbite*>(spell) ) {
        pSpell->revealFrostpower();
    }
    else if ( Thunderstorm* pSpell = dynamic_cast<Thunderstorm*>(spell) ) {
        pSpell->revealThunderpower();
    }
    else if ( Waterbolt* pSpell = dynamic_cast<Waterbolt*>(spell) ) {
        pSpell->revealWaterpower();
    }
    else {
        string scrollName_ = spell->revealScrollName();
        string journal_ = SpellJournal::read();
        long long scrollNameSize = scrollName_.size();
        long long journalSize = journal_.size();
        int table[journalSize+1][scrollNameSize+1];
        
        for (int i = 0; i < scrollNameSize; i++) { table[0][i] = 0; }
        for (int i = 0; i < journalSize; i++) { table[i][0] = 0; }
        
        for (int i = 1; i <= journalSize; i++) {
            for (int j = 1; j <= scrollNameSize; j++) {
                if (journal_[i-1] == scrollName_[j-1]) {
                    table[i][j] = table[i-1][j-1] + 1;
                }
                else { 
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        cout << table[journalSize][scrollNameSize] << endl;
    }
}