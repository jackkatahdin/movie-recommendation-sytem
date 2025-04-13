# M3OEP-cwalsh31-jkhoward

## Charles Walsh & Jack Howard

## Movie Recommendation System & Database
* This is a program designed to recommend the user a movie based on the genres that they enjoy
* With Module 3 it is now also designed as a database which can generate data, graphs and be stored in a website
* Expanded from Module 1 and 2

### Website Here: https://jkhoward.w3.uvm.edu/M3OEP-cwalsh31-jkhoward/site/index.html

* Necessary Installations
    * matplotlib, numpy

* The program starts in C++, and utilizes C++, Python, html, Javascript, and css
    * C++ is the main program, and the first call it makes is to a json database which stores the movies from the csv file to make reading easier for the Javascript.
    * The Javascript grabs the data from the json and uses it to pass to the html. We use html and Javascript to make a website out of the program
    * C++ also calls on the Python script graphing.py to run. Python uses matplotlib to create a graph of the requested data
    * We pass into Python for the sake of matplotlib, first gathering all the data in C++ where it will be faster, then to Python for better graphing capabilities

* Module 3 Concepts
    * Use of Multiple Languages
        * There are 4 main languages used in the program
    * Choice of Languages
        * The languages are used for their strengths and exclusive capabilities that others sometimes cannot do
    * Data Transfer Between Languages
        * The main program passes data to Python via file i/o, and passes data to Javascript via file i/o as well

* Bugs
    * I have not encountered any program breaking bugs

* Future Work
    * Regarding the Python work, there are is a lot of different data that can be graphed in different ways from the dataset. The csv has 11 columns. Some other examples could be rating counts, comparing budgets by year, actor occurences, etc.
    * The website can be expanded to include this data as well, and display graphs

* Citations
    * The csv file used was from the template below, with some fields altered for consistency
    * https://www.kaggle.com/datasets/rajugc/imdb-top-250-movies-dataset?resource=download

* Grading
    * Main program Complexity and Usability
        * 40 points. The program uses all the listed Module 3 concepts
    * Use of Multiple Languages
        * 20 points. The program uses four languages in tandem
    * Choice of Languages
        * 20 points. The languages are used to their strengths to support the others' weaknessnes
    * Data Transfer
        * 20 points. Data is transferred between three different languages
    * Style and Documentation
        * 0 points. All the program is documented and styled
    * Video
        * 0 points. Video has multiple runs, showcases everything
    * Lifespan of project
        * 0 points. Lifespan of project is greater than 7 days. Project was made over a week before the due date. Commits on over 3 separate days.
    * Total: 100 points