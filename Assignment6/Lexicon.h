#ifndef CS197C_LEXICON
#define CS197C_LEXICON

#include <string>
#include <ostream>

using namespace std;

class Data
{
    public:
    string token;
    int c;
};

class Lexicon {
 private:
     Data Map[9999];

 public:

  /**
   * Constructor
   *
   * Takes in a file name, opens that file, tokenizes it, and
   * stores the number of times a particular token occurs in that file.
   */
  Lexicon(string &filename);

  /**
   * Destructor
   *
   * deallocates any internal data structures allocated by the Lexicon.
   */
  ~Lexicon();

  /**
   * count()
   *
   * Returns the total number of tokens counted in the lexicon. This is the sum of all
   * counts of all tokens in the lexicon. Should run in O(1) (constant) time.
   */
  int count();

  /**
   * count(token)
   *
   * Returns the number of times the given token occurs in the lexicon. If the token
   * does not occur, returns 0.
   */
  int count(std::string &token);

  /**
   * contains(token)
   *
   * Returns true if the lexicon contains the given token, false otherwise.
   */
  bool contains(std::string &token);

  /**
   * increment(token)
   *
   * Increments the count of <token> by 1.
   */
  void increment(std::string &token);

  /**
   * increment(token, n)
   *
   * Increments the count of <token> by n.
   */
  void increment(std::string &token, int n);

  /**
   * remove(token)
   *
   * Removes the token from the lexicon.
   */
  void remove(std::string &token);

  /**
   * printLexicographically(ostream &)
   *
   * Takes a reference to an ostream object (such as cout), and prints the contents of the lexicon
   * to that stream. The tokens should be in decreasing lexicographical order, with the count of each token
   * one per line. Each entry and its count is separated by a tab, therefore for entry "fox, 5", the output
   * should be:
   * fox        5
   */
  void printLexicographically(std::ostream &out);

  /**
   * printCardinally(ostream &)
   *
   * Similar to above, but now the entries are sorted descending by frequency instead of by their alphabetical
   * ordering. The output format for the entries is the same as above. So if we have the two entries
   * fox, 5 and jungle, 17. In the above method they are sorted by first part, and printed as:
   *
   * fox        5
   * jungle     17
   *
   * but by cardinality (THIS method):
   *
   * jungle     17
   * fox        5
   *
   * because jungle has a higher count.
   */
  void printCardinally(std::ostream &out);



  // EXTRA CREDIT:

  /**
   * Implement forward and reverse iterators for the Lexicon - the iterators should basically serve to wrap the
   * iterators in the map class (provided you used it). Therefore each entry in your iterator should have a "first" and
   * a "last" field, representing the token and its count, respectively.
   */

  /**
   * distanceFrom(Lexicon &other, double (*scoringFunction)(int count1, int total1, int count2, int total2))
   *
   * A function that returns the distance of this lexicon from another lexicon. You can think of each lexicon really
   * as a multinomial probability distribution of terms - i.e. the probability of "the" occurring is (# of times 'the' occurs) / (total).
   * So, we can use standard 'distance' measurements between probability distributions such as mutual information or the
   * Kullback-Leibler Divergence (KL-Divergence) to get some sense of what lexicons are "closer together" than others.
   * The default cpp file implementation always returns 0.0. You may replace this with your own implementation for extra credit.
   * The 'map' method from the LinkedList assignment is fairly similar to this.
   */
  double distanceFrom(Lexicon &other, double (*scoringFunction)(int count1, int total1, int count2, int total2));
};

#endif
