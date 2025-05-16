#include "raylib.h"
#include <vector>
#include <string>
#include <iostream>

// Base Animal class
class Animal {
protected:
    int x, y;           // Coordinates
    Texture2D texture;  // Animal image texture

public:
    Animal(int x, int y, Texture2D texture) : x(x), y(y), texture(texture) {}

    virtual ~Animal() {
        UnloadTexture(texture);
    }

    virtual std::string makeSound() const {
        return "Some generic animal sound";
    }

    virtual std::string printInfo() const {
        return "Animal at (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // Draw animal texture at its coordinates
    void draw() const {
        DrawTexture(texture, x, y, WHITE);
    }

    // Returns the rectangle bounding the animal (for mouse collision detection)
    Rectangle getBounds() const {
        return Rectangle{ (float)x, (float)y, (float)texture.width, (float)texture.height };
    }
};

// Cow subclass
class Cow : public Animal {
public:
    Cow(int x, int y, Texture2D tex) : Animal(x, y, tex) {}

    std::string makeSound() const override {
        return "Moo!";
    }

    std::string printInfo() const override {
        return "Cow at (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

// Chicken subclass
class Chicken : public Animal {
public:
    Chicken(int x, int y, Texture2D tex) : Animal(x, y, tex) {}

    std::string makeSound() const override {
        return "Cluck!";
    }

    std::string printInfo() const override {
        return "Chicken at (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Farm Simulator v0.8 - Polymorphism Upgrade");

    // Load textures (assumes you have "cow.png" and "chicken.png" in working dir)
    Texture2D cowTexture = LoadTexture("cow.png");
    Texture2D chickenTexture = LoadTexture("chicken.png");

    std::vector<Animal*> animals;
    animals.push_back(new Cow(100, 150, cowTexture));
    animals.push_back(new Chicken(300, 200, chickenTexture));
    animals.push_back(new Cow(500, 100, cowTexture));
    animals.push_back(new Chicken(200, 300, chickenTexture));

    std::string infoText = "Click an animal to see info";
    std::string soundText = "";

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        // Detect mouse click on animals
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bool clickedAnimal = false;
            for (auto animal : animals) {
                if (CheckCollisionPointRec(mousePos, animal->getBounds())) {
                    infoText = animal->printInfo();
                    soundText = animal->makeSound();
                    clickedAnimal = true;
                    break;  // Respond only to one animal per click
                }
            }
            if (!clickedAnimal) {
                infoText = "Clicked empty space";
                soundText = "";
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw all animals
        for (auto animal : animals) {
            animal->draw();
        }

        // Draw info and sound text at bottom
        int padding = 10;
        DrawText(infoText.c_str(), padding, screenHeight - 60, 20, DARKGRAY);
        DrawText(soundText.c_str(), padding, screenHeight - 30, 20, DARKGREEN);

        EndDrawing();
    }

    // Cleanup
    for (auto animal : animals) {
        delete animal;  // This also unloads textures since destructor calls UnloadTexture
    }
    animals.clear();

    CloseWindow();
    return 0;
}
