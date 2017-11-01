#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

#define ALPHA 26

// +-------+---------------------------------------------------------
// | Types |
// +-------+

struct Trie {
    int count;                          // # descendants
    struct Trie *children[ALPHA];       // links to children
};

typedef struct Trie Trie;
typedef struct Trie TrieNode;


// +--------------------+--------------------------------------------
// | Utility Procedures |
// +--------------------+

/**
 * Create a new, empty, trie.
 */
Trie *
trie_new ()
{
  return (Trie *) 0;
} // trie_new

/**
 * Deallocate all the memory associated with a trie.
 */
void
trie_free (Trie * trie)
{
} // trie_free

void
trie_add_helper (Trie *trie, char *str, int index)
{
  if(trie->children[str[i]-97]) {
    
  }
} // add

/**
 * Add an element to the trie.
 * @pre: The element is not in the trie.
 */
void
trie_add (Trie *trie, char *str)
{
  if(trie->children[str[0])
} // add

/**
 * Look up a prefix in the trie.
 */
int
trie_lookup (Trie *trie, char *str)
{
    // fprintf (stderr, "Lookup %s\n", str);
    return 0;
} // lookup

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main()
{

    int numlines;
    char command[5];
    char str[32];   // They say 21, but let's use a power of 2 for fun.
    Trie *trie = trie_new ();

    scanf ("%d", &numlines);
    for (int i = 0; i < numlines; i++)
    {
        scanf ("%s", command);
        scanf ("%s", str);
        if (strcmp (command, "add") == 0)
          trie_add (trie, str);
        else if (strcmp (command, "find") == 0)
          printf ("%d\n", trie_lookup (trie, str));
    }

    // Cleanup
    trie_free (trie);
    return 0;
} // main
