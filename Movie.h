/**
 * Created by Charles Walsh
 * CS2300A
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Cast.h"
#include "Director.h"
#include "Writer.h"

using namespace std;

class Cast;
class Director;
class Person;
class Writer;

/**
 * Enumerated type of all possible movie genres
 */
enum Genre
{
    HORROR,
    ROMANCE,
    COMEDY,
    ACTION,
    ADVENTURE,
    ANIMATION,
    BIOGRAPHY,
    CRIME,
    DRAMA,
    FAMILY,
    DOCUMENTARY,
    FANTASY,
    GAME_SHOW,
    HISTORY,
    MUSICAL,
    MYSTERY,
    NEWS,
    SCI_FI,
    THRILLER,
    WESTERN,
    SPORTS,
    OTHER
};


/**
 * Class representing a movie
 * Fields:
 *     rank: Movie ranking on iMDb
 *     year: Release year of movie
 *     budget: Budget of movie
 *     boxOffice: Amount the movie made
 *     name: Name (title) of movie
 *     certificate: Rating of movie
 *     tagline: Tagline for movie
 *     genre: Vector of genres the movie is listed as
 *     cast: Vector of the cast of the movie
 *     director: Vector of the director(s) of the movie
 *     writer: Vector of the writer(s) of the movie
 */
class Movie
{
private:
    int rank, year, budget, boxOffice;
    string name, certificate, tagline;
    vector<Genre> genre;
    vector<Director> director;
    vector<Cast> cast;
    vector<Writer> writer;
public:
    /*
     * Default constructor
     * Requires: nothing
     * Modifies: nothing
     * Defaults all values to -1 or empty
     */
    Movie();

    /*
     * Constructor taking year and name
     * Requires: year, name
     * Modifies: nothing
     * Takes year and name values for a Movie, defaulting all other values to -1 or empty
     * Useful for checking equivalence between two Movies
     */
    Movie(int year, string name);

    /*
     * Constructor taking all fields
     * Requires: rank, year, budget, boxOffice, name, certificate, tagline, genre, cast, director, writer
     * Modifies: nothing
     * Takes all fields for a Movie, defaulting nothing
     */
    Movie(int rank, int year, int budget, int boxOffice,
          string name, string certificate, string tagline, vector<Genre> genre, vector<Cast> cast,
          vector<Director> director, vector<Writer> writer);

    // Getters
    /**
     * Get respective value
     * Requires: nothing
     * Modifies: nothing
     * Effects: Retrieves respective value
     */
    int getRank() const;
    int getYear() const;
    int getBudget() const;
    int getBoxOffice() const;
    string getName() const;
    string getCertificate() const;
    string getTagline() const;
    vector<Genre> getGenre() const;
    vector<Cast> getCast() const;
    vector<Director> getDirector() const;
    vector<Writer> getWriter() const;


    // Overloaded operators
    /**
     * Overload equivalence operator for two Movies
     * Requires: nothing
     * Modifies: equivalence operator
     * Effects: Checks for equivalence between two Movies determined by their name, and their year of release
     */
    bool operator==(const Movie& other) const;

    /**
     * Overload left shift operator for Movies
     * Requires: nothing
     * Modifies: left shift operator
     * Effects: Allows object of type Movie to be printed in format:
     * name, directed by director
     * Released in year, Rated certificate
     * tagline
     */
    friend ostream& operator<<(ostream& outs, const Movie& movie);

    // unused
    /**
    friend ostream& operator<<(ostream& outs, const Genre genre);
    */


    // Other methods
    /**
     * Load Movies from a csv file
     * Requires: properly formatted csv
     * Modifies: nothing
     * Effects: Reads in a Movie from a csv file, going line by line
     */
    static bool loadFromFile(string fn, vector<Movie> &objs);

    static bool saveToFile(string fn, Movie obj);

    static string genreToString(Genre genre);

    // unused, maybe in a future update :)
    /**
    string getDirectorInput(istream &ins, ostream &outs)
    {
        string directorChoice;
        bool directorInDatabase = false;
        while (!directorInDatabase)
        {
            outs << "Enter your favorite director by first and last name: ";
            ins.clear();
            ins >> directorChoice;

        }

    }
    */
};
#endif //MOVIE_H
