
/** Computer Architecture III - Lesandro Ponciano
  * Work 1 - Flickr Database
  * Group: Igor Machado Seixas
  *        Joao Castro
  *        Paulo Junio
  *
  * Used language: C++
  *
  * For more information please follow to github.com/castrob/ac3_flickr repository
  */

  // Imports
  #include <iostream>
  #include <list>
  #include <algorithm>

  using namespace std;
  //Class photos
  class Photos {
    //Atributes photos
    public:
      double idPhoto;
      double idOwner;
  /**
    * Photos Construtctor
    * @param double idPhoto - It's a id Photos
    * @param double idWOwner = It's a id Owner by photo
    */
    Photos (double idPhoto , double idOwner) {

      this->idPhoto = idPhoto;
      this->idOwner = idOwner;

    }

  };
  //CLass dictionary
  class dictionary {

    //Atributes dictionary
    public:

      list<Photos> photos;
    /**
      * Dictionary Construtctor
      */
      dictionary () {

      }
    /**
      * Method Add Photos
      * @param double idPhoto - It's a id Photos
      * @param double idWOwner = It's a id Owner by photo
      */
      void addPhoto (double idPhoto , double idOwner) {
        Photos tmp (idPhoto,idOwner); //Create object Photo.
        photos.push_back(tmp); //Push_Back tmp in photos list.
      }
    /**
      * Method find Owner
      * @param double idPhoto - It's a id Photos.
      * @return double idWOwner = It's a id Owner by photo.
      */
      double findOwner (double idPhoto) {
        double idOwner = 0.0;
        for(list<Photos>::iterator i = photos.begin(); i != photos.end(); i++){
          if(i->idPhoto == idPhoto) {
            idOwner = i->idOwner;
          }
        }
        return idOwner;
      }

    /**
      * Method Print Photos
      */
      void printPhotos () {
        cout << "Photos Dictionary \n";
        for(list<Photos>::iterator i = photos.begin(); i != photos.end(); i++){
          cout << "idPhoto = " << i->idPhoto << " idOwner = " << i->idOwner << "\n";
        }
      }
  };

/** /
    int main(int argc, char const *argv[]) {

      //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\\

      dictionary d;
      d.addPhoto(623562532,82375273);
      d.addPhoto(3425542,8324234);
      d.addPhoto(2434324,321435);
      d.addPhoto(2342321,12332312);
      d.addPhoto(21314,123133);
      double aux = d.findOwner(623562532);
      cout << "idOwner find = " << aux << "\n";
      d.printPhotos();
      return 0;
    }
/**/

