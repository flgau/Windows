/*
 * Titre : Matrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef MATRICE_H
#define MATRICE_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

template <typename T> class Matrice {

public:
  Matrice();
  // Destructeur
  ~Matrice() = default;
  T operator()(const size_t &posY, const size_t &posX) const;
  // Lecture du fichier
  bool chargerDepuisFichier(const std::string &nomFichier);
  bool lireElement(const std::string &elementFichier, const size_t &posY,
                   const size_t &posX);
  // Remplir un matrice
  bool ajouterElement(T element, const size_t &posY, const size_t &posX);
  // Faire une copie
  std::unique_ptr<Matrice<T>> clone() const;
  // Setters
  void setHeight(size_t height);
  void setWidth(size_t width);
  // Getters
  size_t getHeight() const;
  size_t getWidth() const;

private:
  std::vector<std::vector<T>> elements_;
  size_t height_;
  size_t width_;
};

namespace {
static constexpr int CAPACITE_MATRICE = 100;
}

/**
 * @brief constructeur par défaut de la classe
 */
template <typename T> inline Matrice<T>::Matrice()
    :height_(0),
    width_(0),
    elements_ (CAPACITE_MATRICE)
{

  // TO DO

}
/**
 * @brief retourne le nombre de lignes de la matrice
 * @return l'attribut height_ de l'objet
 */ 
template <typename T> inline size_t Matrice<T>::getHeight() const {
  return height_;
}
/**
 * @brief retourne le nombre de colonnes de la matrice
 * @return l'attribut width_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getWidth() const {
  return width_;
}
template<typename T>
inline T Matrice<T>::operator()(const size_t& posY, const size_t& posX) const
{
    if (posY > height_ || posX > width_)
    {
        return T();
    }
    else {
        return elements_[posY][posX];



    }

}

template <typename T> bool Matrice<T>::ajouterElement(T element, const size_t& posY, const size_t& posX) {

    if (posY > height_ || posX > width_) {
        return false;
    }
    
    elements_[posY][posX] = element;
    return true;


}

template<typename T>
inline std::unique_ptr<Matrice<T>> Matrice<T>::clone() const
{
    return std::make_unique<Matrice<T>>(*this);
}

template<typename T>
inline void Matrice<T>::setHeight(size_t height)
{
    int initHeight = (height == CAPACITE_MATRICE + 10 ? height_ = CAPACITE_MATRICE : height_ = height);

}

template<typename T>
inline void Matrice<T>::setWidth(size_t width)
{ 
    width_ = width;
}


template<typename T>
inline bool Matrice<T>::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    if (fichier) {
        elements_.clear();
        std::string ligne;
        
        width_ = CAPACITE_MATRICE;
        height_ = CAPACITE_MATRICE;

        int nombreL = 0;
        int hauteur = 0;
        int largeur = 0;
        while (std::getline(fichierLecture, ligne))
        {    
            if (ligne !=L)
            {
                if (!lireElement(ligne, hauteur, largeur++)) 
                {
                    return false;
                }
                
            }
            else
            {
                hauteur++;
                largeur = 0;
            }
        }
        width_ = largeur;
        height_ = hauteur;
        return true;

    }
    else {
        return false;
    }

       
}

template <typename T> bool Matrice<T>::lireElement(const std::string& elementFichier, const size_t& posY,
    const size_t& posX) 
{
    T element;
    if (elementFichier>>element)
    {
        //static_cast<T> (elementFichier);
        return Matrice::ajouterElement(element, posY, posX);T

    }
    return false;
   
        
    

}



#endif











