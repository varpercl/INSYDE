#include "trainingset.h"

template<class TrainingPattern>
TrainingSet<TrainingPattern>::TrainingSet() : list<TrainingPattern>()
{

}

template<class TrainingPattern>
TrainingSet<TrainingPattern>::TrainingSet(int n) : list<TrainingPattern>(n)
{
}

//template<class TrainingPattern>
//TrainingPattern TrainingSet<TrainingPattern>::getTrainingPattern()
//{
//}

//template<class TrainingPattern>
//void TrainingSet<TrainingPattern>::setNumberInputs(int ni)
//{

//}

//template<class TrainingPattern>
//int TrainingSet<TrainingPattern>::getNumberInputs()
//{
//    return 0;
//}

//template<class TrainingPattern>
//void TrainingSet<TrainingPattern>::setNumberOutputs(int no)
//{

//}

//template<class TrainingPattern>
//int TrainingSet<TrainingPattern>::getNumberOutputs()
//{
//    return 0;
//}

//template<class TrainingPattern>
//void TrainingSet<TrainingPattern>::insertTrainingPattern(const TrainingPattern &tp)
//{
//}

