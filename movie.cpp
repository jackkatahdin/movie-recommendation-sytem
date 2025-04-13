/**
 * Created by Charles Walsh
 * CS 2300A
*/

#include <sstream>
#include "Movie.h"
#include "Person.h"
#include "Writer.h"
#include "Cast.h"
#include "Director.h"

using namespace std;

Movie::Movie()
{
    rank = 0;
    year = 0;
    budget = 0;
    boxOffice = 0;
    name = "NA";
    certificate = "NA";
    tagline = "NA";
    genre = {};
    cast = {};
    director = {};
    writer = {};
}

Movie::Movie(int year, string name)
{
    rank = 0;
    this-> year = year;
    budget = 0;
    boxOffice = 0;
    this-> name = name;
    certificate = "NA";
    tagline = "NA";
    genre = {};
    cast = {};
    director = {};
    writer = {};
}

Movie::Movie(int rank, int year, int budget, int boxOffice,
          string name, string certificate, string tagline, vector<Genre> genre, vector<Cast> cast,
          vector<Director> director, vector<Writer> writer)
{
    this-> rank = rank;
    this-> year = year;
    this-> budget = budget;
    this-> boxOffice = boxOffice;
    this-> certificate = certificate;
    this-> name = name;
    this-> tagline = tagline;
    this-> genre = genre;
    this-> cast = cast;
    this-> director = director;
    this-> writer = writer;
}


int Movie::getRank() const
{
    return rank;
}
int Movie::getYear() const
{
    return year;
}
int Movie::getBudget() const
{
    return budget;
}
int Movie::getBoxOffice() const
{
    return boxOffice;
}
string Movie::getName() const
{
    return name;
}
string Movie::getCertificate() const
{
    return certificate;
}

string Movie::getTagline() const
{
    return tagline;
}
vector<Genre> Movie::getGenre() const
{
    return genre;
}

vector<Cast> Movie::getCast() const
{
    return cast;
}

vector<Director> Movie::getDirector() const
{
    return director;
}
vector<Writer> Movie::getWriter() const
{
    return writer;
}


bool Movie::operator==(const Movie& other) const
{
    return (name == other.getName() && year == other.getYear());
}

ostream& operator<<(ostream& outs, const Movie& movie)
{
    outs << movie.getName() << ", directed by ";
    for (int i = 0; i < movie.getDirector().size(); i++)
    {
        outs << movie.getDirector()[i];
        if (i < movie.getDirector().size() - 1)
        {
            outs << ", ";
        }
    }
    outs << "\nReleased in " << movie.getYear() << ", Rated " << movie.getCertificate() << "\n'" << movie.getTagline() << "'";
    return outs;
}

// unused
/**
ostream& operator<<(ostream& outs, const Genre genre)
{
    switch (genre)
    {
        case ROMANCE: outs << "Romance"; break;
        case COMEDY: outs << "Comedy"; break;
        case ACTION: outs << "Action"; break;
        case ADVENTURE: outs << "Adventure"; break;
        case ANIMATED: outs << "Animated"; break;
        case BIOGRAPHY: outs << "Biography"; break;
        case CRIME: outs << "Crime"; break;
        case DRAMA: outs << "Drama"; break;
        case FAMILY: outs << "Family"; break;
        case GAME_SHOW: outs << "Game Show"; break;
        case HISTORY: outs << "History"; break;
        case MUSICAL: outs << "Musical"; break;
        case MYSTERY: outs << "Mystery"; break;
        case NEWS: outs << "News"; break;
        case SCI_FI: outs << "Sci-Fi"; break;
        case THRILLER: outs << "Thriller"; break;
        case WESTERN: outs << "Western"; break;
        case SPORTS: outs << "Sports"; break;
        case OTHER: outs << "Other"; break;
        default: outs <<"N/A"; break;
    }
    return outs;
}
*/


string Movie::genreToString(Genre genre)
{
    switch (genre)
    {
    case HORROR: return "Horror";
    case ROMANCE: return "Romance";
    case COMEDY: return "Comedy";
    case ACTION: return "Action";
    case ADVENTURE: return "Adventure";
    case ANIMATION: return "Animation";
    case BIOGRAPHY: return "Biography";
    case CRIME: return "Crime";
    case DRAMA: return "Drama";
    case FAMILY: return "Family";
    case DOCUMENTARY: return "Documentary";
    case FANTASY: return "Fantasy";
    case GAME_SHOW: return "Game Show";
    case HISTORY: return "History";
    case MUSICAL: return "Musical";
    case MYSTERY: return "Mystery";
    case NEWS: return "News";
    case SCI_FI: return "Sci-Fi";
    case THRILLER: return "Thriller";
    case WESTERN: return "Western";
    case SPORTS: return "Sports";
    case OTHER: return "Other";
    default: return "N/A";
    }

}

bool Movie::loadFromFile(string fn, vector<Movie> &objs)
{
    ifstream fin;
    fin.open(fn);
    // Cannot find file
    if (!fin)
    {
        return false;
    }
    // Skip header
    string header = "";
    getline(fin, header);

    // Initialize values
    int rank, year, budget, boxOffice;
    string name, certificate, tagline;
    vector<Genre> genre;
    vector<Director> director;
    vector<Cast> cast;
    vector<Writer> writer;
    char comma;
    int counter = 1;

    while (fin && fin.peek() != EOF)
    {
        /**
        if (objs.size() == 251)
        {
            return true;
        }
        */
        // Sentinel values
        rank, year, budget, boxOffice = -1;
        name, certificate, tagline = "INVALID";
        genre.clear();
        cast.clear();
        director.clear();
        writer.clear();
        comma = ',';

        fin >> rank;
        /**
        if (rank != counter)
        {
            cout << rank << " != " << counter << endl;
            return false;
        }
        */
        // Some movie names, genres, casts, directors, and writers fields have
        // commas within them, so check the csv file which will automatically put
        // anything containing commas into quotations, making sure to proceed
        // properly depending on the case
        fin >> comma;
        if (fin.peek() == '"')
        {
            getline(fin, name, '"');
            getline(fin, name, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, name, ',');
        }

        string genreString;
        if (fin.peek() == '"')
        {
            getline(fin, genreString, '"');
            getline(fin, genreString, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, genreString, ',');
        }
        // Handle genres differently based on their enumerated nature
        stringstream ss(genreString);
        string includedGenre;
        while (getline(ss, includedGenre, ','))
        {
            if (includedGenre == "Horror") genre.push_back(Genre::HORROR);
            else if (includedGenre == "Romance") genre.push_back(Genre::ROMANCE);
            else if (includedGenre == "Comedy") genre.push_back(Genre::COMEDY);
            else if (includedGenre == "Action") genre.push_back(Genre::ACTION);
            else if (includedGenre == "Adventure") genre.push_back(Genre::ADVENTURE);
            else if (includedGenre == "Animation") genre.push_back(Genre::ANIMATION);
            else if (includedGenre == "Biography") genre.push_back(Genre::BIOGRAPHY);
            else if (includedGenre == "Crime") genre.push_back(Genre::CRIME);
            else if (includedGenre == "Drama") genre.push_back(Genre::DRAMA);
            else if (includedGenre == "Family") genre.push_back(Genre::FAMILY);
            else if (includedGenre == "Documentary") genre.push_back(Genre::DOCUMENTARY);
            else if (includedGenre == "Fantasy") genre.push_back(Genre::FANTASY);
            else if (includedGenre == "Game Show") genre.push_back(Genre::GAME_SHOW);
            else if (includedGenre == "History") genre.push_back(Genre::HISTORY);
            else if (includedGenre == "Musical") genre.push_back(Genre::MUSICAL);
            else if (includedGenre == "Mystery") genre.push_back(Genre::MYSTERY);
            else if (includedGenre == "News") genre.push_back(Genre::NEWS);
            else if (includedGenre == "Sci-Fi") genre.push_back(Genre::SCI_FI);
            else if (includedGenre == "Thriller") genre.push_back(Genre::THRILLER);
            else if (includedGenre == "Western") genre.push_back(Genre::WESTERN);
            else if (includedGenre == "Sports") genre.push_back(Genre::SPORTS);
            else if (includedGenre == "Other") genre.push_back(Genre::OTHER);
        }
        if (fin.peek() == '"')
        {
            getline(fin, certificate, '"');
            getline(fin, certificate, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, certificate, ',');
        }

        if (fin.peek() == '"')
        {
            getline(fin, tagline, '"');
            getline(fin, tagline, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, tagline, ',');
        }
        fin >> budget;
        fin >> comma;
        fin >> boxOffice;
        fin >> comma;
        string castString;
        if (fin.peek() == '"')
        {
            getline(fin, castString, '"');
            getline(fin, castString, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, castString, ',');
        }
        stringstream ssCast(castString);
        string castMember;
        while (getline(ssCast, castMember, ','))
        {
            cast.push_back(Cast(castMember));
        }
        string directorString;
        if (fin.peek() == '"')
        {
            getline(fin, directorString, '"');
            getline(fin, directorString, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, directorString, ',');
        }
        stringstream ssDirector(directorString);
        string directorMember;
        while (getline(ssDirector, directorMember, ','))
        {
            director.push_back(Director(directorMember));
        }
        string writerString;
        if (fin.peek() == '"')
        {
            getline(fin, writerString, '"');
            getline(fin, writerString, '"');
            fin >> comma;
        }
        else
        {
            getline(fin, writerString, ',');
        }
        stringstream ssWriter(writerString);
        while (getline(ss, writerString, ','))
        {
            // BLAH
            // maybe?
            writer.push_back(Writer(writerString));
        }
        fin >> year;
        // save all info into a movie, proceed to next
        Movie movie(rank, year, budget, boxOffice, name, certificate, tagline, genre, cast, director, writer);
        objs.push_back(movie);
        counter++;
    }
    fin.close();
    return true;
}

bool Movie::saveToFile(string fileName, Movie obj)
{
    ofstream fout(fileName, ofstream::app);
    if (!fout)
    {
        return false;
    }

    // use this for building movie method added afterfout << fileName.back.getRank() + 1 << endl;
    fout << obj.getRank() << ",";

    fout << "\"" << obj.getName() << "\",";

    fout << "\"";
    for (int i = 0; i < obj.getGenre().size(); i++)
    {
        fout << genreToString(obj.getGenre()[i]);
        if (i < obj.getGenre().size() - 1)
        {
            fout << ",";
        }
    }
    fout << "\",";

    fout << "\"" << obj.getCertificate() << "\",";
    fout << "\"" << obj.getTagline() << "\",";
    fout << obj.getBudget() << ",";
    fout << obj.getBoxOffice() << ",";

    fout << "\"";
    for (int i = 0; i < obj.getCast().size(); i++)
    {
        fout << obj.getCast()[i];
        if (i < obj.getCast().size() - 1)
        {
            fout << ",";
        }
    }
    fout << "\",";

    fout << "\"";
    for (int i = 0; i < obj.getDirector().size(); i++)
    {
        fout << obj.getDirector()[i];
        if (i < obj.getDirector().size() - 1)
        {
            fout << ",";
        }
    }
    fout << "\",";
    fout << "\"";
    for (int i = 0; i < obj.getWriter().size(); i++)
    {
        fout << obj.getWriter()[i];
        if (i < obj.getWriter().size() - 1)
        {
            fout << ",";
        }
    }
    fout << "\",";

    fout << obj.getYear();
    fout << endl;
    fout.close();
    return true;
}

