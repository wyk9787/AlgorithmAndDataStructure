#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "template.h"

void get_next(String T, int *next) {
	int i = 1, j = 0;
	next[1] = 0;
	int len = strlen(T)-1;
	while (i < len) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int Index_KMP(String S, String T, int pos) {
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	int len1 = strlen(S)-1, len2 = strlen(T)-1;
	while (i <= len1 && j <= len2) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > len2)
		return i - len2;
	else
		return 0;
}
int main() {
	String A = "abcababca", B = "abcabx";
	String S, T;
	for (int i = 0; i < strlen(A); i++)
		S[i + 1] = A[i];
	S[strlen(A) + 1] = '\0';
	for (int i = 0; i < strlen(B); i++)
		T[i + 1] = B[i];
	T[strlen(B)] = '\0' ;
	int i = Index_KMP(S, T, 0);

}