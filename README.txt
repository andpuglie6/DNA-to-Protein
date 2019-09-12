This is a conversion of the program "DNA to Protein in Python 3" written by
Amartya Ranjan Saikia. The code can be found on GeeksforGeeks at the link:
https://www.geeksforgeeks.org/dna-protein-python-3/

DNA is important for life as it allows cells to store, retrieve, and 
translate genetic instructions for the function of intracellular processes.
DNA is composed of four nucleotides in long chains: Adenine, Cytosine,
Guanine, and Thymine. Every three character sequence of nucleotides
corresponds to an amino acid i.e. the codon. Codons correspond to
a specific amino acid and all proteins are built from just 20 amino acids.

Within this program the genetic sequence is supplied from the NBCI database
of nucleotides. This specific example comes with a copy and pasted "origin"
from the genetic sequence encoding "Drosophila melanogaster hexokinase A,
transcript variant A (Hex-A), mRNA." This can be found at the link:
https://www.ncbi.nlm.nih.gov/nuccore/NM_080109.4

There are several other sequences that can be used to test this program. 
What is necessary for this program to function properly is a "Coding DNA 
Sequence". NBCI supplies both an "origin" (a code sequence that contains 
the entire CDS) and a specific CDS region which can be identified as 
"[int]..[int]. In the case of the Drosophilia genome, this can be seen as
"330..1955".

Ideally this program will be expanded to not only take in documents but also
allow the user to take directly from a DNA database and start converting to
proteins. It may also allow room to convert from DNA to RNA and allow users
to create their own DNA/RNA/Protein strands. Reverse engineering RNA to DNA
may also be a future function.