#include "Movie.h"
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#ifdef _WIN32
const string python = "py";
#else
// const string python = "python";
#endif

/*
 * Gather different types of user input
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Gets values from user, with input validation
*/
int getIntFromUser(string message);
string getStringFromUser(string message);
Movie getMovieFromUser();

/*
 * Write data into a txt file for Python to graph
 * Requires: name of graph, data for file
 * Modifies: data.txt
 * Effects: Overwrites data into data.txt
 */
bool saveToGraphing(string graphName, vector<auto> data);

/*
 * Print all possible types of movie genres
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Prints all available genres
*/
void printGenres();

/*
 * Convert an object of enum Genre to a string
 * Requires: Genre
 * Modifies: Nothing
 * Effects: Returns passed Genre as string type
*/
string genreToString(Genre genre);

void generateMoviesJSON(const vector<Movie>& movies) {
    const string jsonPath = "../site/movies.json";

    ofstream jsonFile(jsonPath);
    if (!jsonFile) {
        cerr << "fatal error << jsonPath"
             << "probably permissions\n";
        exit(EXIT_FAILURE);
    }

    auto escape = [](const string& s) {
        string out;
        for (char c : s) {
            if (c == '"' || c == '\\') out += '\\';
            out += c;
        }
        return out;
    };

    jsonFile << "[\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        const Movie& m = movies[i];

        const int budget = m.getBudget() > 0 ? m.getBudget() : -1;
        const int boxOffice = m.getBoxOffice() > 0 ? m.getBoxOffice() : -1;

        jsonFile << "  {\n"
                 << "    \"title\": \"" << escape(m.getName()) << "\",\n"
                 << "    \"year\": " << m.getYear() << ",\n"
                 << "    \"genres\": [";

        const auto& genres = m.getGenre();
        for (size_t j = 0; j < genres.size(); ++j) {
            jsonFile << '"' << escape(genreToString(genres[j])) << '"';
            if (j < genres.size() - 1) jsonFile << ", ";
        }

        jsonFile << "],\n"
                 << "    \"certificate\": \"" << escape(m.getCertificate()) << "\",\n"
                 << "    \"budget\": " << (budget > 0 ? to_string(budget) : "null") << ",\n"
                 << "    \"boxOffice\": " << (boxOffice > 0 ? to_string(boxOffice) : "null") << ",\n"
                 << "    \"tagline\": \"" << escape(m.getTagline()) << "\"\n"
                 << "  }";

        if (i < movies.size() - 1) jsonFile << ",\n";
    }
    jsonFile << "\n]\n";

    if (jsonFile.fail()) {
        cerr << "error\n";
        exit(EXIT_FAILURE);
    }

}


/**
 * Main
 * Welcome to the movie recommendation system!
 * This program gathers input from a user, and uses it to recommend a movie from
 * iMDb's list of top 250 rated movies
 */
int main(int argc, char* argv[])
{
    // Read in all the movies from the CSV file
    vector<Movie> movieCharts;
    string fn = "../imdb_movies.csv";
    if (Movie::loadFromFile(fn, movieCharts))
        {
        cout << "\n" << movieCharts.size()
            << " records read from file" << std::endl;
        generateMoviesJSON(movieCharts);
        int firstRank = movieCharts.front().getRank();
        string firstName = movieCharts.front().getName();
        string firstCertificate = movieCharts.front().getCertificate();
        cout << "The first row ID read was " << firstRank << ", '"
        << firstName << "' rated " << firstCertificate << "." << endl;
        int lastRank = movieCharts.back().getRank();
        string lastName = movieCharts.back().getName();
        string lastCertificate = movieCharts.back().getCertificate();
        cout << "The last row ID read was " << lastRank << ", '"
        << lastName << "' rated " << lastCertificate << "." << endl;
    }
    else
        {
            cout << "Something went wrong." << endl;
        }

    // Conditions for the loop, the Genre that will be stored by the end of it to recommend a movie
    bool exit = false;
    bool getMovie = false;
    Genre userGenre;


    while (!exit && !getMovie)
    {
        cout << "\nWelcome to the movie recommendation system!\n To start, enter the name of your "
            "favorite movie.\nTo add a movie to the list, enter (a)\nTo graph movie data, enter (g)\n To exit, enter (e)" << endl;
        string favoriteMovie = getStringFromUser("Enter a movie: ");
        // Allow exit in case of accidental start
        if (favoriteMovie == "e")
        {
            exit = true;
        }

        else if (favoriteMovie == "a")
        {
            Movie userInputMovie = getMovieFromUser();
            Movie::saveToFile(fn, userInputMovie);
        }
        else if (favoriteMovie == "g")
        {
           cout << "What would you like to graph?\nNumber of movies for each genre (a)\nMovies released per year (b)" << endl;
           string graphChoice = getStringFromUser("Enter an option: ");
           while (graphChoice != "a" && graphChoice != "b")
           {
               cout << "Invalid input. ";
               graphChoice = getStringFromUser("Enter an option: ");
           }
           string graphName;
           if (graphChoice == "a")
           {
               graphName = "Genres";
               int horror = 0;
               int romance = 0;
               int comedy = 0;
               int action = 0;
               int adventure = 0;
               int animation = 0;
               int biography = 0;
               int crime = 0;
               int drama = 0;
               int family = 0;
               int documentary = 0;
               int fantasy = 0;
               int gameShow = 0;
               int history = 0;
               int musical = 0;
               int mystery = 0;
               int news = 0;
               int sciFi = 0;
               int thriller = 0;
               int western = 0;
               int sports = 0;
               int other = 0;
               for (const auto& movie : movieCharts)
               {
                   vector<Genre> check = movie.getGenre();
                   for (auto & i : check)
                   {
                       switch (i)
                       {
                       case HORROR:
                           horror++;
                           break;
                       case ROMANCE:
                           romance++;
                           break;
                       case COMEDY:
                           comedy++;
                           break;
                       case ACTION:
                           action++;
                           break;
                       case ADVENTURE:
                           adventure++;
                           break;
                       case ANIMATION:
                           animation++;
                           break;
                       case BIOGRAPHY:
                           biography++;
                           break;
                       case CRIME:
                           crime++;
                           break;
                       case DRAMA:
                           drama++;
                           break;
                       case FAMILY:
                           family++;
                           break;
                       case DOCUMENTARY:
                           documentary++;
                           break;
                       case FANTASY:
                           fantasy++;
                           break;
                       case GAME_SHOW:
                           gameShow++;
                           break;
                       case HISTORY:
                           history++;
                           break;
                       case MUSICAL:
                           musical++;
                           break;
                       case MYSTERY:
                           mystery++;
                           break;
                       case NEWS:
                           news++;
                           break;
                       case SCI_FI:
                           sciFi++;
                           break;
                       case THRILLER:
                           thriller++;
                           break;
                       case WESTERN:
                           western++;
                           break;
                       case SPORTS:
                           sports++;
                           break;
                       default:
                           other++;
                       }
                   }
               }
               vector<int> data = {horror, romance, comedy, action, adventure, animation, biography,
               crime, drama, family, documentary, fantasy, gameShow, history, musical, mystery, news, sciFi,
               thriller, western, sports};
               saveToGraphing(graphName, data);
           }
           else if (graphChoice == "b")
           {
               graphName = "Years";
               map<int, int> yearCount;
               for (const auto& movie : movieCharts)
               {
                   yearCount[movie.getYear()]++;
               }
               vector<string> data;
               for (const auto& year : yearCount)
               {
                   stringstream ss;
                   ss << year.first << " " << year.second;
                   data.push_back(ss.str());
               }
               saveToGraphing(graphName, data);
           }
           string command = python + " ../graphing.py";
           system(command.c_str());
           cout << "over now";
           return 0;
       }

        // To here
        else
        {
            bool movieFound = false;
            // Searches the vector of movies to see if it matches a name anywhere
            for (const auto& movie : movieCharts)
            {
                if (movie.getName() == favoriteMovie)
                {
                    cout << "\nThat movie sounds familiar... Do you know what year it came out?" << endl;
                    // Equivalence between two movies is determined based on their name and release year
                    int favoriteMovieYear = getIntFromUser("Enter the release year of the movie: ");
                    Movie userMovie = Movie(favoriteMovieYear, favoriteMovie);

                    // If the movie is in the vector, it will randomly select a genre from that movie
                    // to make its recommendation off of
                    if (userMovie == movie)
                    {
                        movieFound = true;
                        cout << "\nI know that one! In that case, ";
                        vector<Genre> genres = movie.getGenre();
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<int> distribution(0, genres.size() - 1);
                        int randomIndex = distribution(gen);
                        userGenre = genres[randomIndex];
                    }
                    // Same movie name, but different release year. Movie is not in the vector
                    else
                    {
                        cout << "\nI know of a movie with the same name, but have never heard of that one!\n";
                    }
                }
            }
            // This is where it will end up in most cases,
            // if the user enters an unrecognized movie, it asks for the genre they want to watch
            if (!movieFound)
            {
                int userGenreInt = -1;
                while (userGenreInt < 0 || userGenreInt > 20)
                {
                    cout << "\n";
                    printGenres();

                    cout << "What genre of movie are you looking for?\n"
                            "Enter a corresponding number to the available genres!" << endl;
                    userGenreInt = getIntFromUser("Enter an integer value: ");
                    userGenreInt--;
                    userGenre = Genre(userGenreInt);
                    cout << "\n" << endl;
                }
            }
            getMovie = true;
        }
    }
    // If the program was not exited
    if (getMovie)
    {
        // Gather all movies that share the user's genre and save them all in a vector of movies
        vector<Movie> sharedGenres;
        for (const auto& movie : movieCharts)
        {
            vector<Genre> genres = movie.getGenre();
            if (find(genres.begin(), genres.end(), userGenre) != genres.end())
            {
                sharedGenres.push_back(movie);
            }
        }
        // Randomly select a movie from the vector to recommend
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(0, sharedGenres.size() - 1);
        int randomIndex = distribution(gen);
        Movie randomMovie = sharedGenres[randomIndex];
        cout << "I recommend\n" << randomMovie << endl;
    }
    cout << "Thanks for participating!" << endl;

    return 0;
}


string getStringFromUser(string message)
{
    string userStr;
    bool pass = false;
    while (!pass)
    {
        cout << message;
        getline(cin, userStr);
        // Checks to see if there is any input at all
        if (userStr.empty())
        {
            cout << "No input. ";
        }
        // Anything else is acceptable
        else
        {
            pass = true;
        }
    }
    return userStr;
}

Movie getMovieFromUser()
{
    int rank, year, budget, boxOffice;
    int userGenreInt = -1;
    string name, certificate, tagline;
    Genre userGenre;
    vector<Genre> genre;
    vector<Director> director;
    vector<Cast> cast;
    vector<Writer> writer;
    string castMember = ",", directorMember = ",", writerMember = ",";

    name = getStringFromUser("Enter the title of the movie: ");
    certificate = getStringFromUser("Enter the certificate of the movie (rating): ");
    tagline = getStringFromUser("Enter the tagline of the movie: ");
    while (userGenreInt != 22)
    {
            printGenres();
            cout << "22. COMPLETE\n";

            cout << "What genre of movie are you looking for?\n"
                    "Enter a corresponding number to the available genres!" << endl;
            userGenreInt = getIntFromUser("Enter an integer value: ");

            if (userGenreInt > 0 && userGenreInt < 22)
            {
                cout << "made it to the if statement";
                userGenre = Genre(userGenreInt - 1);
                genre.push_back(userGenre);
            }
    }
    year = getIntFromUser("Enter the release year of the movie: ");
    rank = getIntFromUser("Enter the movie rank on iMDB: ");
    budget = getIntFromUser("Enter the budget of the movie: ");
    boxOffice = getIntFromUser("Enter the box office of the movie: ");
    while (castMember.back() == ',')
    {
        castMember = getStringFromUser("Enter a cast member\n"
                                       "If you wish to add more, end with a ',': ");
        if (castMember.back() == ',')
        {
            string castMemberComRemoved = castMember.substr(0, castMember.size() - 1);
            cast.push_back(Cast(castMemberComRemoved));
        }
        else
        {
            cast.push_back(Cast(castMember));
        }
    }
    while (directorMember.back() == ',')
    {
        directorMember = getStringFromUser("Enter a director\n"
                                       "If you wish to add more, end with a ',': ");
        if (directorMember.back() == ',')
        {
            string directorMemberComRemoved = directorMember.substr(0, directorMember.size() - 1);
            director.push_back(Director(directorMemberComRemoved));

        }
        else
        {
            director.push_back(Director(directorMember));
        }
    }
    while (writerMember.back() == ',')
    {
        writerMember = getStringFromUser("Enter a writer\n"
                                       "If you wish to add more than one, end with a ',': ");
        if (writerMember.back() == ',')
        {
            string writerMemberComRemoved = writerMember.substr(0, writerMember.size() - 1);
            writer.push_back(Writer(writerMemberComRemoved));
        }
        else
        {
            writer.push_back(Writer(writerMember));
        }
    }
    return {rank, year, budget, boxOffice, name, certificate, tagline, genre, cast, director, writer};
}

int getIntFromUser(string message)
{
    int intNum;
    bool pass = false;
    string str;
    while (!pass)
    {
        cout << message;
        getline(cin, str);
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
        // Check for any input at all
        if (str.empty())
        {
            cout << "No input. ";
            continue;
        }
        stringstream ss(str);
        ss >> intNum;
        // Checks to see if there is anything more than one integer
        if (!ss.eof())
        {
            cout << "Invalid input. ";
        }
        else
        {
            pass = true;
        }
    }
    return intNum;
}

void printGenres()
{
    cout << "All Genres: " << endl;
    for (int i = 0; i < OTHER; i++)
    {
        Genre currentGenre = static_cast<Genre>(i);
        cout << i + 1 << ". " << genreToString(currentGenre) << endl;
    }
    cout << endl;
}

string genreToString(Genre genre)
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

bool saveToGraphing(string graphName, vector<auto> data)
{
    ofstream fout("../data.txt");
    fout << graphName << endl;
    for (int i = 0; i < data.size(); i++)
    {
        fout << data[i] << endl;
    }
    return true;
}

