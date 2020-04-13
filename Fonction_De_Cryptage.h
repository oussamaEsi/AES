// Le nombre de colonnes pour la matrice state de l'AES.
#define Nb 4
// Le nombre de rondes dans l'AES.
extern int Nr;
// Le nombre de mots de 32 bits dans la clé Key.
extern int Nk;
// in    : Bloc clair.
// out   : Bloc chiffré.
// state : Bloc intermédiaires.
extern unsigned char in[16], out[16], state[4][4];
// RoundKey : Sous-clés.
extern unsigned char RoundKey[240];
// Key : la clé de chiffrement.
extern unsigned char Key[32];
// Rcon : utiliser dans la KeyExpansion.
extern int Rcon[255];
// xtime est une macro : le produit de {02} et l'argument de Xtime modulo {1b}.
#define xtime(x)   ((x<<1) ^ (((x>>7) & 1) * 0x1b)) // c'est un décalage d’un seul bit vers la gauche, si son bit de poids fort est égal à 0,
                        //sinon elle est égale à la valeur elle-même décalée d’un seul bit vers la gauche, suivi d’un XOR avec la valeur {1B}.
/*****************************************************************************************************/
void AddRoundKey(int round);
/*****************************************************************************************************/
void SubBytes();
/*****************************************************************************************************/
void ShiftRows();
/*****************************************************************************************************/
void MixColumns();
/*****************************************************************************************************/
void Cipher();
