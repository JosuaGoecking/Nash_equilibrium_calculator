/**
    Program name:   nash_equilibrium.cc
    Purpose:        Compute how many and which Nash equilibria a given game has.
    Details:        The program starts by reading in the number of strategies for the two players followed by their
                    names and the respective payout for each strategy given the strategy used by the other player.
                    Afterwards it lookes for Nash equilibria by finding the strategy with the highest payout for each
                    strategy of the opposing player. If it finds a combination of strategies for which both player 1
                    and 2 get the highest payout it considers it a Nash equilibrium and prints it out.
                    Finally, the number of Nash equilibria in the game are displayed.
                    
    Author:         Josua Goecking
    GitHub:         https://github.com/JosuaGoecking/Nash_equilibrium_calculator
    
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Check if the given value is the highest one in the vector
bool is_max(vector <double> vector, double vector_value){
  double max = -1000000000000;
  for(unsigned i=0; i<vector.size(); i++){
    if(vector[i]>max){max=vector[i];}
  }
  if(max==vector_value){return true;}
  else{return false;}
}

// Functions to allow for a nice Output
// Get maximum tab size for the strat1/strat2 output
int get_tab_width(vector <string> pl1, vector <string> pl2){
    int pl1_size=-1;
    int pl2_size=-1;
    for (unsigned i=0; i<pl1.size(); i++){
        if ((int) pl1[i].length()>pl1_size){pl1_size = pl1[i].length();}
    }
    for (unsigned i=0; i<pl2.size(); i++){
        if ((int) pl2[i].length()>pl2_size){pl2_size = pl2[i].length();}
    }
    return pl1_size+pl2_size+1;
}

// Optimize the spacing according to the naming of the strategies
void optimal_spacing(string left, string right, int max_width){
    string spaces="";
    for(int i=0; i<max_width-left.length(); i++){
        spaces+=" ";
    }
    cout << left << spaces << "\t\t" << right;
}

int main(){

// Number of strategies for both players
 int N_strat_pl1;
 int N_strat_pl2;
 bool same = false;

// Declare vectors, string for naming, double for computing, bool for finding Nash equilibria
 vector <string> strat_pl1;
 vector <string> strat_pl2;
 vector <double> player1;
 vector < vector<double> > payout_pl1;
 vector <double> player2;
 vector < vector<double> > payout_pl2;
 vector <bool> max_payout_pl1;
 vector < vector<bool> > max_payout_matrix_pl1;
 vector <bool> max_payout_pl2;
 vector < vector<bool> > max_payout_matrix_pl2;
 
 // Number of Nash equilibria in the game
 int N_neq=0;

// Initialize the vectors
  strat_pl1.clear();
  strat_pl2.clear();
  payout_pl1.clear();
  payout_pl2.clear();
  max_payout_matrix_pl1.clear();
  max_payout_matrix_pl2.clear();

// Check whether the payout has to be maximized or minimized and set the sign accordingly
string mode;  
cout << "Minimize or maximize the payout? [min/max]\n";
cin >> mode;

int sgn;
if (mode == "max"){
    sgn=1;
}
else{
    sgn=-1;
}

// Read in the number of strategies for each player
cout << "Number of strategies for player 1...\n";
cin >>  N_strat_pl1;
cout << "and player 2:\n";
cin >> N_strat_pl2;

if (N_strat_pl1 == N_strat_pl2){
    same = true;
    N_strat_pl2 = N_strat_pl1;
}
// Read in the name of the strategy for each player 
if (same){cout << "Name strategies for both players:\n";}
else {cout << "Name strategies for player 1:\n";}
for(unsigned i=0; i<N_strat_pl1; i++){string input;
    cout << i+1 << ": "; 
    cin >> input;
    strat_pl1.push_back(input);
    if (same){strat_pl2.push_back(input);}
    }

// If the strategies differ, type in those for player 2
if (!same){
    cout << "Name strategies for player 2:\n";
    for(unsigned i=0; i<N_strat_pl2; i++){string input;
        cout << i+1 << ": ";
        cin >> input;
        strat_pl2.push_back(input);    
    }
}

int max_width = get_tab_width(strat_pl1, strat_pl2);
cout << "\n";

// Specify the payout for each strategy combinations
if (same){optimal_spacing("A/B", "Payout for strategy A given strategy B is played by the other player\n", max_width);}
else {optimal_spacing("A/B", "Payout for strategy A for player 1 given player 2 plays strategy B\n", max_width);}
 for(unsigned i=0; i<N_strat_pl1; i++){player1.clear();
    for(unsigned j=0; j<N_strat_pl2; j++){ double input;
        string output = strat_pl1[j]+"/"+strat_pl2[i];
        optimal_spacing(output, "", max_width);
        cin >> input;
        player1.push_back(sgn*input);
        if (same){player2.push_back(sgn*input);}  
    }
    payout_pl1.push_back(player1);
    if (same){payout_pl2.push_back(player2);}
 }

// Read in payouts for player 2 if they differ
if (!same){cout << "\n";
    optimal_spacing("A/B", "Payout for strategy A for player 2 given player 1 plays strategy B\n", max_width);
    for(unsigned i=0; i<N_strat_pl1; i++){player2.clear();
        for(unsigned j=0; j<N_strat_pl2; j++){ double input;
            string output = strat_pl1[i]+"/"+strat_pl2[j];
            optimal_spacing(output, "", max_width);
            cin >> input;
            player2.push_back(sgn*input);
    }
    payout_pl2.push_back(player2);
    }
}
 
 cout << "\n";
 
// Loop over the payouts and put the max payout matrix to true where the payout is maximal
 for(unsigned i=0; i<payout_pl1.size(); i++){max_payout_pl1.clear();
    for(unsigned j=0; j<payout_pl1[i].size(); j++){
      max_payout_pl1.push_back(is_max(payout_pl1[i], payout_pl1[i][j]));
    }
    max_payout_matrix_pl1.push_back(max_payout_pl1);
  }

// Do the same for player 2
 for(unsigned i=0; i<payout_pl2.size(); i++){max_payout_pl2.clear();
     for(unsigned j=0; j<payout_pl2[i].size(); j++){
      max_payout_pl2.push_back(is_max(payout_pl2[i], payout_pl2[i][j]));
    }
    max_payout_matrix_pl2.push_back(max_payout_pl2);
  }

// Check whether there is a strategy for which both payouts are maximized, that would then be a Nash equilibrium
for(unsigned i=0; i<max_payout_matrix_pl1.size(); i++){
    for(unsigned j=0; j<max_payout_matrix_pl2.size(); j++){
        if(max_payout_matrix_pl1[i][j] && max_payout_matrix_pl2[j][i]){N_neq++;
	    cout << "The strategy (" << strat_pl1[i] << ", " << strat_pl2[j] << ") with payout (" << abs(payout_pl1[i][j]) << ", " << abs(payout_pl2[j][i]) << ") is a Nash equilibrium!\n";
       }
     }
   }

// Print out how many Nash equilibria this game has
if(N_neq>1){
    cout << "Altogether this games has " << N_neq << " Nash equilibria!"<< "\n";}
    else if (N_neq==1){cout << "This game has one Nash equilibrium!"<< "\n";}
    else if (N_neq==0){cout << "This game has no Nash equilibria!"<< "\n";}
}
