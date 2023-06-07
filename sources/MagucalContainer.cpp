#include"MagicalContainer.hpp"
#include"iostream"
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std; 
namespace ariel{
    //add element to the container 
    void MagicalContainer::addElement(int element) {
    
        auto it = std::lower_bound(elements.begin(), elements.end(), element);

        auto addele = elements.insert(it, element);

        Prime_elements.clear();

        for (auto& elem : elements) {
            
            if (IsPrime(elem)) {

                Prime_elements.push_back(&elem);
            }
        }
    }
    const int& MagicalContainer::getElementAt(size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }


    //remove element from the container 
    void MagicalContainer::removeElement(int element){
       
        auto it = find(elements.begin(), elements.end(), element);
        
        if(it != elements.end()){
            
            if(*it == element){
               
                elements.erase(it);
            }
        }
        else{
            
            throw runtime_error("The element you searched for is not in the vector");
        }
        Prime_elements.clear();
        for(size_t i = 0; i < elements.size(); ++i){
         
            if(IsPrime(elements[i])){
             
                Prime_elements.push_back(&elements[i]);
            }
        }
    }

    // get the size of the container 
    size_t MagicalContainer::size(){
        return elements.size(); 
    }
    // cheack if the number is prime or not 
    bool MagicalContainer::IsPrime (int number){
        if(number <= 1 ){
            return false; 
        }
        int sqrtN= static_cast<int>(sqrt(number)); 
        for(int i =2; i<=sqrtN; ++i){
            if(number % i==0){
                return false;
            }
        }
        return true; 
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &&other) noexcept: container(other.container), currentIndex(other.currentIndex){}
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other){
        if(this!= &other){
            if(&container != &other.container)
            throw std::runtime_error("cannt assign iterators  from another containers"); 
            currentIndex=other.currentIndex; 

        }
        return *this; 
    }
    
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other)const{
        
        return currentIndex != other.currentIndex; 
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other)const{
        //return (currentIndex==other.currentIndex)&&(&container==&other.container); 
        bool ans = (currentIndex==other.currentIndex)&&(&container==&other.container); 
        return ans; 
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other)const{
        
        if(currentIndex >= container.size() || other.currentIndex >= container.size()){
            return false;
        }
         bool ans=currentIndex < other.currentIndex;  
         return ans; 
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other)const{
 
        if(currentIndex >= container.size() || other.currentIndex >= container.size()){
            return false;
        }
         bool ans=currentIndex > other.currentIndex;
         return ans;  
    }
    int MagicalContainer::AscendingIterator::operator*() const {
        if(currentIndex >= container.size()){
            throw runtime_error("out of rang "); 
        }
        return (container.getElementAt(currentIndex)); 
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        if(currentIndex >= container.size()){
            throw runtime_error("out of rang "); 
        }
        currentIndex++; 
        return *this;
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &&other) noexcept: container(other.container), currentIndex(other.currentIndex){}
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
        if(this!= &other){
            if(&container != &other.container)
            throw runtime_error("cannt assign iterators  from another container"); 
            currentIndex=other.currentIndex; 

        }
        return *this; 
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other)const{
         
        return currentIndex == other.currentIndex && &container==&other.container; 
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other)const{
        
        return !(*this==other); 
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other)const{
        
        bool ans =currentIndex <other.currentIndex;
        return ans;   
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other)const{
        bool ans=currentIndex >other.currentIndex;
        return ans;  
    }
    int MagicalContainer::SideCrossIterator::operator*() const {
        size_t index;
        if(currentIndex % 2 != 0){
             index = container.size() - 1 - ((currentIndex - 1) / 2);
           
            
        }
        else{
            index = currentIndex / 2;
        }
        return (container.getElementAt(index));

    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
        if(currentIndex >= container.size() || *this==end()){
            throw runtime_error("out of rang "); 
        }
        currentIndex++; 
        return *this;
    }



    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &&other) noexcept: container(other.container), currentIndex(other.currentIndex){}
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other){
        if(&container != &other.container){
            throw runtime_error("cannt assign iterators  from another container"); 

        }
        if(this!=&other){
            this->currentIndex=other.currentIndex; 
        }
        return *this; 
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other)const{
        
        return (currentIndex == other.currentIndex) && (&container==&other.container);  
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other)const{

        return !(*this== other); 
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other)const{

        return currentIndex < other.currentIndex; 
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)const{
        return currentIndex > other.currentIndex; 

    }
    int MagicalContainer::PrimeIterator::operator*() const {
        if(currentIndex >= container.Prime_elements.size()){
            throw runtime_error("out of rang "); 
        }
        return *(container.Prime_elements.at(currentIndex)); 
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
        if(currentIndex >= container.Prime_elements.size()){
            throw runtime_error("out of rang "); 
        }
        currentIndex++; 
        return *this;
    }


    
    


}