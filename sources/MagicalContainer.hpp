# pragma once
#include <vector>
using namespace std; 
namespace ariel{
    class MagicalContainer{
        private:
         vector<int>elements; 
         //vector<const int *>Ascding_elements; 
         //vector<const int *>CrossSide_elements; 
         vector<const int *>Prime_elements; 
         bool IsPrime(int number);

        public: 
         MagicalContainer(){}
         void addElement(int element); 
         void removeElement(int element); 
         const int& getElementAt(size_t index) const ; 
         size_t size(); 

        class AscendingIterator{
            private: 
             MagicalContainer &container; 
             size_t currentIndex; 
             //AscendingIterator(MagicalContainer &container, size_t currentindex): container(container), currentIndex(currentindex){}
            public: 
             ~AscendingIterator(){}//destructor 
             AscendingIterator(MagicalContainer &Magic_C): container(Magic_C), currentIndex(0) {}//defult constructor 
             AscendingIterator(const AscendingIterator& other) : container(other.container), currentIndex(other.currentIndex) {}// copy constructor 
             AscendingIterator(MagicalContainer &container, size_t currentindex): container(container), currentIndex(currentindex){}
             AscendingIterator(const AscendingIterator&& other)noexcept ; 
             //AscendingIterator():container(nullptr), currentIndex(0){}
             AscendingIterator &operator=(const AscendingIterator &other); 
             bool operator==(const AscendingIterator &other)const; 
             bool operator!=(const AscendingIterator &other)const; 
             bool operator>(const AscendingIterator &other)const; 
             bool operator<(const AscendingIterator &other)const; 
             int operator*()const; 
             AscendingIterator &operator++(); 
             AscendingIterator begin(){
               AscendingIterator iterator0(container); 
               iterator0.currentIndex=0; 
               return iterator0; 
                 
             }
                
             AscendingIterator end()const{
               AscendingIterator iterator0(container); 
               iterator0.currentIndex= container.size(); 
               return iterator0; 
                
             } 

        }; 
        class SideCrossIterator {
            private: 
             MagicalContainer &container; 
             size_t currentIndex; 
             //SideCrossIterator(MagicalContainer *container, size_t currentindex): container(container), currentIndex(currentindex){}
            public: 
             ~SideCrossIterator(){}//destructor 
             SideCrossIterator(MagicalContainer &Magic_C): container(Magic_C), currentIndex(0) {}//defult constructor 
             SideCrossIterator(const SideCrossIterator& other) : container(other.container), currentIndex(other.currentIndex) {}// copy constructor 
             SideCrossIterator(MagicalContainer &container, size_t currentindex): container(container), currentIndex(currentindex){}
             SideCrossIterator(const SideCrossIterator&& other)noexcept ; 
             //SideCrossIterator(): container(nullptr), currentIndex(0){}

             SideCrossIterator &operator=(const SideCrossIterator &other); 
             
             bool operator==(const SideCrossIterator &other)const ; 
             bool operator!=(const SideCrossIterator &other)const ; 
             bool operator>(const SideCrossIterator &other)const; 
             bool operator<(const SideCrossIterator &other)const; 
             int operator*()const ; 
             SideCrossIterator &operator++(); 
             SideCrossIterator begin(){
                return SideCrossIterator(container,0); 
             }
                
             SideCrossIterator end()const{
                return SideCrossIterator(container, container.size()); 
             } 
        };
        class PrimeIterator {
            private: 
             MagicalContainer &container; 
             size_t currentIndex; 
             PrimeIterator(MagicalContainer &container, size_t currentindex): container(container), currentIndex(currentindex){}
            public: 
             ~PrimeIterator(){}//destructor 
             PrimeIterator(MagicalContainer &Magic_C): container(Magic_C), currentIndex(0) {}//defult constructor 
             PrimeIterator(const PrimeIterator& other) : container(other.container), currentIndex(other.currentIndex) {}// copy constructor 
             //PrimeIterator(MagicalContainer *container, size_t currentindex): container(container), currentIndex(currentindex){}
             PrimeIterator(const PrimeIterator&& other)noexcept ;
             //PrimeIterator(): container(nullptr), currentIndex(0){}
             PrimeIterator &operator=(const PrimeIterator &other); 
             bool operator==(const PrimeIterator &other)const ; 
             bool operator!=(const PrimeIterator &other)const ; 
             bool operator>(const PrimeIterator &other)const; 
             bool operator<(const PrimeIterator &other)const; 
             int operator*()const ; 
             PrimeIterator &operator++(); 
             PrimeIterator begin(){
               PrimeIterator iterator0(container); 
               iterator0.currentIndex=0; 
               return iterator0; 
                
             }
                
             PrimeIterator end()const{
                return PrimeIterator(container, container.Prime_elements.size()); 
             } 
         }; 
        


   }; 
}; 