# 🛠 Compilateur et flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS =

# 🏆 Nom du projet
PROJECT_NAME = RPN

# 🖥️ Détection de l'OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CXXFLAGS   += -I/usr/include
	LDFLAGS    += -L/usr/lib
else ifeq ($(UNAME_S), Darwin)
	CXXFLAGS   += -I/opt/homebrew/include
	LDFLAGS    += -L/opt/homebrew/lib -framework Cocoa
else ifeq ($(UNAME_S), Windows_NT)
	CXXFLAGS   +=
	LDFLAGS    +=
endif

# 📂 Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# 📌 Fichiers sources et objets
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/RPN.cpp
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 📚 Inclusion des headers
INCLUDES = -I$(INCLUDE_DIR)

# 🎯 Règle principale
all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ_FILES) $(LDFLAGS) -o $@
	@echo "✅ Compilation terminée !"

# 🛠️ Compilation des fichiers objets (prise en charge des sous-dossiers)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $< -o $@
	@echo "🔨 Compilé : $< -> $@"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 🧹 Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)
	@echo "🗑️  Fichiers objets nettoyés."

# 🗑️ Nettoyage complet (objets et exécutable)
fclean: clean
	rm -f $(PROJECT_NAME)
	@echo "🗑️  Nettoyage complet effectué."

# 🔄 Reconstruction
re: fclean all

# ▶️ Exécution du projet avec support d'arguments (optionnel)
run: all
	./$(PROJECT_NAME) $(ARGS)

.PHONY: all clean fclean re run
