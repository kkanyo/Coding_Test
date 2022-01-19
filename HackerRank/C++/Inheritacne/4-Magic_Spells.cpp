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
    if ( Fireball* pSpell = dynamic_cast<Fireball*>(spell) ) {  // down casting
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
        
        int scrollNameSize = scrollName_.size();
        int journalSize = journal_.size();
        
        int table[scrollNameSize+1][journalSize+1];
        
        // Initalize 'table'
        for (int i = 0; i < scrollNameSize+1; i++) { table[i][0] = 0; }
        for (int i = 0; i < journalSize+1; i++) { table[0][i] = 0; }
        
        // LCS(Longest Common Subsequence) algorithm
        for (int i = 1; i <= scrollNameSize; i++) {
            for (int j = 1; j <= journalSize; j++) {
                if (scrollName_[i-1] == journal_[j-1]) {
                    table[i][j] = table[i-1][j-1] + 1;
                }
                else { 
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        cout << table[scrollNameSize][journalSize] << '\n';
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}