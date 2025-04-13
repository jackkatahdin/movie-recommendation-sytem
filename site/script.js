async function loadMovies() {
    try {
        const response = await fetch('movies.json');
        if (!response.ok) throw new Error(`HTTP error ${response.status}`);
        const movies = await response.json();
        return movies.map(movie => ({
            ...movie,
            genres: Array.isArray(movie.genres) ? movie.genres : [movie.genres]
        }));
    } catch (error) {
        console.error("Failed to load movies:", error);
        return [];
    }
}

function displayMovies(movies) {
    const resultDiv = document.getElementById('recommendationResult');

    if (!movies.length) {
        resultDiv.innerHTML = `<p class="error">No movies found in database</p>`;
        return;
    }

    const html = `
        <div class="movie-stats">
            <p>Total movies: ${movies.length}</p>
            <p>Newest: ${Math.max(...movies.map(m => m.year))}</p>
            <p>Oldest: ${Math.min(...movies.map(m => m.year))}</p>
        </div>
        <div class="movie-grid">
            ${movies.map(movie => `
                <div class="movie-card">
                    <h3>${movie.title} (${movie.year})</h3>
                    <div class="movie-details">
                        <p><strong>Genre:</strong> ${movie.genres.join(', ')}</p>
                        <p><strong>Rating:</strong> ${movie.certificate}</p>
                        ${movie.budget ? `<p><strong>Budget:</strong> $${movie.budget.toLocaleString()}</p>` : ''}
                        ${movie.boxOffice ? `<p><strong>Box Office:</strong> $${movie.boxOffice.toLocaleString()}</p>` : ''}
                        ${movie.tagline ? `<p class="tagline">"${movie.tagline}"</p>` : ''}
                    </div>
                </div>
            `).join('')}
        </div>
    `;

    resultDiv.innerHTML = html;
}

async function handleRecommendation() {
    const searchType = document.getElementById('searchType').value;
    const resultDiv = document.getElementById('recommendationResult');
    resultDiv.innerHTML = '<div class="loading">Searching...</div>';

    try {
        const movies = await loadMovies();
        if (!movies.length) throw new Error('No movies available');

        if (searchType === 'movie') {
            const title = document.getElementById('movieInput').value.trim().toLowerCase();
            const matches = title ? movies.filter(m =>
                m.title.toLowerCase().includes(title)
            ) : [];

            if (matches.length) {
                resultDiv.innerHTML = `
                    <h3>Found ${matches.length} ${matches.length === 1 ? 'match' : 'matches'}:</h3>
                    <div class="movie-grid">
                        ${matches.map(m => `
                            <div class="movie-card">
                                <h4>${m.title} (${m.year})</h4>
                                <p>${m.genres.join(', ')}</p>
                                ${m.certificate ? `<p>Rated ${m.certificate}</p>` : ''}
                            </div>
                        `).join('')}
                    </div>
                `;
            } else {
                resultDiv.innerHTML = `<p class="error">No matches found for "${title}"</p>`;
            }

        } else if (searchType === 'genre') {
            const genre = document.getElementById('genreSelect').value.toLowerCase();
            const matches = movies.filter(m =>
                m.genres.some(g => g.toLowerCase() === genre)
            );

            if (matches.length) {
                const randomIndex = Math.floor(Math.random() * matches.length);
                const recommendation = matches[randomIndex];
                resultDiv.innerHTML = `
                    <div class="recommendation-box">
                        <h3>Our Recommendation:</h3>
                        <div class="movie-card highlight">
                            <h2>${recommendation.title} (${recommendation.year})</h2>
                            <p class="genre">${recommendation.genres.join(', ')}</p>
                            <div class="stats">
                                ${recommendation.certificate ? `<p>Rating: ${recommendation.certificate}</p>` : ''}
                                ${recommendation.boxOffice ? `<p>Box Office: $${recommendation.boxOffice.toLocaleString()}</p>` : ''}
                            </div>
                            ${recommendation.tagline ? `<p class="tagline">"${recommendation.tagline}"</p>` : ''}
                        </div>
                    </div>
                `;
            } else {
                resultDiv.innerHTML = `<p class="error">No ${genre} movies found</p>`;
            }
        }
    } catch (error) {
        resultDiv.innerHTML = `<p class="error">Error: ${error.message}</p>`;
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const searchTypeSelect = document.getElementById('searchType');
    const movieSearchDiv = document.getElementById('movieSearch');
    const genreSearchDiv = document.getElementById('genreSearch');

    const updateUI = () => {
        movieSearchDiv.style.display = searchTypeSelect.value === 'movie' ? 'block' : 'none';
        genreSearchDiv.style.display = searchTypeSelect.value === 'genre' ? 'block' : 'none';
    };

    searchTypeSelect.addEventListener('change', updateUI);
    updateUI();

    document.querySelectorAll('button').forEach(button => {
        button.addEventListener('click', handleRecommendation);
    });

    document.getElementById('movieInput').addEventListener('keypress', (e) => {
        if (e.key === 'Enter') handleRecommendation();
    });

    loadMovies().then(displayMovies);
});