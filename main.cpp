#include <iostream>
using namespace std;

//Отсутствие инкапсуляции
class Pub {
public:
    string averageScore;
    string academicPerformance;
    string studentsProgress;
};

//Инкапсуляция с помощью set/get

class StudentsRatingSetGet {
protected:
    string averageScore;
    string academicPerformance;
    string studentsProgress;

public:
    string SetAverageScore(const string &averageScore) {
        StudentsRatingSetGet:: averageScore = averageScore;
    }

    string GetAverageScore() {
        return StudentsRatingSetGet:: averageScore;
    }

    string SetAcademicPerformance(const string &academicPerformance) {
        StudentsRatingSetGet:: academicPerformance = academicPerformance;
    }

    string GetAcademicPerformance() {
        return StudentsRatingSetGet:: academicPerformance;
    }

    string SetStudentsProgress(const string &studentsProgress) {
        StudentsRatingSetGet:: studentsProgress = studentsProgress;
    }

    string GetStudentsProgress() {
        return StudentsRatingSetGet:: studentsProgress;
    }
};

class StudentsRatingFP : public StudentsRatingSetGet {
public:
    int operator > (StudentsRatingFP &fp) {
        return (averageScore > fp.GetAverageScore() ? 1 : 0);
    }

    inline int operator < (StudentsRatingFP &fp) {
        return (averageScore < fp.GetAverageScore() ? 1 : 0);
    }
};

class Characteristic: public StudentsRatingSetGet {
private:
    string studentsName;
    string roomTheGradeBook;
public:
    Characteristic(string averageScore, string academicPerformance, string studentsProgress) {
        studentsName = studentsName;
        roomTheGradeBook = roomTheGradeBook;
        averageScore = averageScore;
        academicPerformance = academicPerformance;
        studentsProgress = studentsProgress;
    }
};

class Shopping {
    class Purchases {
    public:
        virtual unsigned int Basket() = 0;
    };

    class Apple: public Purchases {
        unsigned int Basket() {
            return 5;
        }
    };

    class Milk: public Purchases {
        unsigned int Basket() {
            return 2;
        }
    };

    class Bread: public Purchases {
        unsigned int Basket() {
            return 1;
        }
    };

    Purchases* purchases;

public:
    unsigned int sum = 500;

    void CollectBasket(Shopping* shopping) {
        shopping->sum -= purchases->Basket();
    }

    Shopping(int okPrice) {
        if(okPrice) {
            purchases = new Apple;
            purchases = new Bread;
        }
        else {
            purchases = new Milk;
        }
    }
};

class Buyer: public Shopping {
public:
    Buyer(int okPrice): Shopping(okPrice) {};

    void CollectBasket(Shopping* shopping) {
        Shopping::CollectBasket(shopping);
        sum--;
    }
};


int main() {
#if 500
    Shopping shoppingByuMilk(20);
    Shopping shoppingByuApple(10);
    Shopping shoppingByuBread(25);
    Buyer buyerWithMilk(20);
    Shopping milk(25);
    Shopping apple(10);
    Shopping bread(10);
    shoppingByuMilk.CollectBasket(&milk);
    printf("%d\n", milk.sum);
    shoppingByuApple.CollectBasket(&apple);
    printf("%d\n", apple.sum);
    shoppingByuBread.CollectBasket(&bread);
    printf("%d\n", bread.sum);
#endif
    return 0;
}
