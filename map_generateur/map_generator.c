#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour initialiser une map
void initializeMap(int width, int height, char map[height][width]) {
    // Entoure la map de murs
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = '1'; // Mur
            } else {
                map[i][j] = '1'; // Par défaut, tout est mur
            }
        }
    }
}

// Fonction pour creuser des chemins aléatoires dans un monde ouvert
void carveOpenWorld(int width, int height, char map[height][width], float openRatio) {
    srand(time(NULL));
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if ((float)rand() / RAND_MAX < openRatio) {
                map[i][j] = '0'; // Crée une case libre
            }
        }
    }
}

// Fonction pour tracer un chemin garanti entre départ et sortie
void carveGuaranteedPath(int width, int height, char map[height][width], int startX, int startY, int endX, int endY) {
    // Trace un chemin direct (vertical, puis horizontal)
    int x = startX, y = startY;
    while (x != endX) {
        map[x][y] = '0'; // Chemin libre
        x += (endX > x) ? 1 : -1;
    }
    while (y != endY) {
        map[x][y] = '0'; // Chemin libre
        y += (endY > y) ? 1 : -1;
    }
    map[endX][endY] = '0'; // Assure que la sortie est libre
}

// Fonction pour placer des collectibles aléatoires
void addCollectibles(int width, int height, char map[height][width], int collectibleCount) {
    int placed = 0;
    while (placed < collectibleCount) {
        int x = rand() % (height - 2) + 1;
        int y = rand() % (width - 2) + 1;
        if (map[x][y] == '0') { // Place uniquement sur une case libre
            map[x][y] = 'C';
            placed++;
        }
    }
}

// Fonction pour sauvegarder la map dans un fichier
void saveMapToFile(int width, int height, char map[height][width], const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%c", map[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    int width = 15;  // Largeur de la map
    int height = 5; // Hauteur de la map
    float openRatio = 0.7; // Ratio de cases ouvertes (50%)
    int collectibleCount = 5; // Nombre de collectibles

    char map[height][width];
    int startX = 1, startY = 1;              // Position du départ
    int endX = height - 2, endY = width - 2; // Position de la sortie

    // Initialise la map
    initializeMap(width, height, map);

    // Crée un monde ouvert en creusant des chemins aléatoires
    carveOpenWorld(width, height, map, openRatio);

    // Trace un chemin garanti entre le départ et la sortie
    carveGuaranteedPath(width, height, map, startX, startY, endX, endY);

    // Place le départ et la sortie
    map[startX][startY] = 'P';
    map[endX][endY] = 'E';

    // Ajoute des collectibles
    addCollectibles(width, height, map, collectibleCount);

    // Sauvegarde la map dans un fichier
    saveMapToFile(width, height, map, "so_long.ber");

    printf("Map générée et sauvegardée dans 'so_long.ber'.\n");
    return 0;
}

