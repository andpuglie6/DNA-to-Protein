// C++ Program converted from Python
// DNA conversion to Protein

# include <iostream>
# include <map>
# include <fstream>
# include <string>
using namespace std;

string translate(string sequenceAppended){
	
	//Create a map that shows the specific codon and its proper...
	
	map<string, char> DNAToProtein;
	
	DNAToProtein["ATA"] = 'I';
	DNAToProtein["ATC"] = 'I';
	DNAToProtein["ATT"] = 'I';
	DNAToProtein["ATG"] = 'M';
	DNAToProtein["ACA"] = 'T';
	DNAToProtein["ACC"] = 'T';
	DNAToProtein["ACG"] = 'T';
	DNAToProtein["ACT"] = 'T';
	DNAToProtein["AAC"] = 'N';
	DNAToProtein["AAT"] = 'N';
	DNAToProtein["AAA"] = 'K';
	DNAToProtein["AAG"] = 'K';
	DNAToProtein["AGC"] = 'S';
	DNAToProtein["AGT"] = 'S';
	DNAToProtein["AGA"] = 'R';
	DNAToProtein["AGG"] = 'R';
	DNAToProtein["CTA"] = 'L';
	DNAToProtein["CTC"] = 'L';
	DNAToProtein["CTG"] = 'L';
	DNAToProtein["CTT"] = 'L';
	DNAToProtein["CCA"] = 'P';
	DNAToProtein["CCC"] = 'P';
	DNAToProtein["CCG"] = 'P';
	DNAToProtein["CCT"] = 'P';
	DNAToProtein["CAC"] = 'H';
	DNAToProtein["CAT"] = 'H';
	DNAToProtein["CAA"] = 'Q';
	DNAToProtein["CAG"] = 'Q';
	DNAToProtein["CGA"] = 'R';
	DNAToProtein["CGC"] = 'R';
	DNAToProtein["CGG"] = 'R';
	DNAToProtein["CGT"] = 'R';
	DNAToProtein["GTA"] = 'V';
	DNAToProtein["GTC"] = 'V';
	DNAToProtein["GTG"] = 'V';
	DNAToProtein["GTT"] = 'V';
	DNAToProtein["GCA"] = 'A';
	DNAToProtein["GCC"] = 'A';
	DNAToProtein["GCG"] = 'A';
	DNAToProtein["GCT"] = 'A';
	DNAToProtein["GAC"] = 'D';
	DNAToProtein["GAT"] = 'D';
	DNAToProtein["GAA"] = 'E';
        DNAToProtein["GAG"] = 'E';   
	DNAToProtein["GGA"] = 'G'; 
	DNAToProtein["GGC"] = 'G';
	DNAToProtein["GGG"] = 'G';
	DNAToProtein["GGT"] = 'G';
	DNAToProtein["TCA"] = 'S';
	DNAToProtein["TCC"] = 'S';
	DNAToProtein["TCG"] = 'S';
	DNAToProtein["TCT"] = 'S';
	DNAToProtein["TTC"] = 'F';
	DNAToProtein["TTT"] = 'F';
	DNAToProtein["TTA"] = 'L';
	DNAToProtein["TTG"] = 'L';
	DNAToProtein["TAC"] = 'Y';
	DNAToProtein["TAT"] = 'Y';
	DNAToProtein["TAA"] = '_';
	DNAToProtein["TAG"] = '_';
	DNAToProtein["TGC"] = 'C';
	DNAToProtein["TGT"] = 'C';
	DNAToProtein["TGA"] = '_';
	DNAToProtein["TGG"] = 'W';
	
	string protein;
	
	if(sequenceAppended.length() % 3 == 0){
		
		for(int i = 0; i <= sequenceAppended.length(); i += 3){
			
			string codon = sequenceAppended.substr(i, 3);			
			protein += DNAToProtein.find(codon)->second;
		}
	}	
	
	protein = protein.substr(0, protein.length() - 1);
	return protein;
}

string readSeq(ifstream& inputFile){
	
	string sequence;
	char character;
	
	if (inputFile.is_open()) {
		
		while (inputFile.get(character)){
			
			if(isalpha(character)){
				
				if(character >= 'a' && character <= 'z'){
					
					character = character - 32;
				}
				
				sequence += character;
			}
		}
		
		inputFile.close();
	} else {
		
		cout << "Unable to open file"; 
	}
	
	return sequence;
}

int main(){
	
	char character;
	
	ifstream DNAFile ("DNA_sequence_original.txt");
	ifstream proteinFile ("amino_acid_sequence_original.txt");
  	
  	string proteinSequence = readSeq(proteinFile);
	string DNA = readSeq(DNAFile);

	int firstDigit;
	int secondDigit;
	
	cout << "What is the first CDS number? ";
  	cin >> firstDigit;
  	firstDigit = firstDigit - 1;
  	
  	cout << "What is the second CDS number?";
  	cin >> secondDigit;
  	secondDigit = secondDigit - firstDigit - 3;
	
	string translatedProteinSequence = translate(DNA.substr(firstDigit, secondDigit)); // Formula for CDS is firstdigit = firstdigit - 1, second digit = second digit - firstdigit - 3
	
	// cout << translatedProteinSequence;

	if(translatedProteinSequence == proteinSequence){
    	cout << "true";
	}
	  	
  	return 0;
}
