#include "sdb.h"

#define MAXCOURSENUM 10
#define MINCOURSENUM 3
#define MAXNUM 50

student stdArr[50];
course courseArr[10]; /*there are only 10 courses (with IDs from 1 to 10) and each course can take up to 10 students*/

static void ValidateValue(uint32 *num, uint32 checker);
static void SelectionSort();
static void Swap(student *num1, student *num2);

/**
 * @brief initializes the student Array
 * @param
 * @return bool variable (retVal) returns:
 *         true : if the list is full
 *         false : if the list is not full
 */
bool stdArrInit()
{
    bool retVal = false;
    uint8 l_counter = 0;
    for (l_counter = 0; l_counter < MAXNUM; l_counter++)
    {
        stdArr[l_counter].Student_ID = ~(0);
    }
    return retVal;
}

/**
 * @brief initializes all courses
 * @param
 * @return bool variable (retVal) returns:
 *         true : if the list is full
 *         false : if the list is not full
 */
bool coursesArrInit()
{
    bool retVal = false;
    uint8 counter = 0;
    for (counter = 0; counter < 10; counter++)
    {
        courseArr[counter].ID = counter + 1;
        courseArr[counter].StudentsNum = 0;
    }
    retVal = true;
    return retVal;
}

/**
 * @brief checks if the student list is full
 * @param
 * @return bool variable (retVal) returns:
 *         true : if the list is full
 *         false : if the list is not full
 */
bool SDB_IsFull()
{
    bool retVal = false;
    uint8 counter = 0;
    while (stdArr[counter].Student_ID != ~(0) && counter < MAXNUM)
    {
        counter++;
    }
    if (counter == MAXNUM)
    {
        retVal = true;
    }
    return retVal;
}

/**
 * @brief gets the number of students in the array
 * @param
 * @return uint8 variable (counter) that represents the number of students in the list
 */
uint8 SDB_GetUsedSize()
{
    uint8 counter = 0;
    while (stdArr[counter].Student_ID != ~(0) && counter < MAXNUM)
    {
        counter++;
    }
    return counter;
}

/**
 * @brief Adds a new student data to the list
 * @param
 * @return bool variable (retVal) returns:
 *         true : if the list is full
 *         false : if the list is not full
 */
bool SDB_AddEntry()
{
    bool retVal = false;
    uint8 latestElement = SDB_GetUsedSize();
    uint8 l_counter = 0;
    uint32 temp = 0;
    uint8 index = 0;
    if (SDB_IsFull() == false)
    {
        printf("Enter Student ID "
               "Warning !!! The ID must not be less than 1 "
               "\n Student ID : ");
        scanf("%u", &(temp));
        ValidateValue(&(temp), 1);
        SelectionSort();
        while (true == SDB_IsIdExist(temp, &index))
        {
            printf("Error !!! ID already existing Number, please enter another ID : ");
            scanf("%u", &(temp));
            ValidateValue(&(temp), 1);
        }
        stdArr[latestElement].Student_ID = temp;
        printf("Enter Student Year "
               "(Warning !!! The year must not be less than 1 )"
               "\n Student Year : ");
        scanf("%u", &(stdArr[latestElement].Student_year));
        ValidateValue(&(stdArr[latestElement].Student_year), 1);
        printf("Enter the Courses "
               " ( Warning !!! there is no course ID less than 1)"
               " : ");
        for (l_counter = 1; l_counter <= 3; l_counter++)
        {
            printf("\n\n => Course (%i) ID : ", l_counter);
            switch (l_counter)
            {
            case 1:
                scanf("%u", &(stdArr[latestElement].Course1_ID));
                fflush(stdin);
                while (((courseArr[(stdArr[latestElement].Course1_ID) - 1].StudentsNum) == MAXCOURSENUM) || (stdArr[latestElement].Course1_ID > 10))
                {
                    if ((courseArr[(stdArr[latestElement].Course1_ID) - 1].StudentsNum) == MAXCOURSENUM)
                        printf("The course reached the max number of enrolled students, please choose another course : ");
                    else if (stdArr[latestElement].Course1_ID > 10)
                        printf("Input Value exceeding Maximum Value , please enter a value between 1 and 10 : ");
                    scanf("%u", &(stdArr[latestElement].Course1_ID));
                }
                printf("\n => Course (%i) Grade : ", l_counter);
                scanf("%u", &(stdArr[latestElement].Course1_grade));
                fflush(stdin);
                (courseArr[(stdArr[latestElement].Course1_ID) - 1].StudentsNum)++;
                break;
            case 2:
                scanf("%u", &(stdArr[latestElement].Course2_ID));
                fflush(stdin);
                while (((courseArr[(stdArr[latestElement].Course2_ID) - 1].StudentsNum) == MAXCOURSENUM) || (stdArr[latestElement].Course2_ID) == (stdArr[latestElement].Course1_ID) || (stdArr[latestElement].Course2_ID > 10))
                {
                    if ((courseArr[(stdArr[latestElement].Course2_ID) - 1].StudentsNum) == MAXCOURSENUM)
                        printf("The course reached the max number of enrolled students, please choose another course : ");
                    else if ((stdArr[latestElement].Course2_ID) == (stdArr[latestElement].Course1_ID))
                        printf("Error !! Duplicate Value , please choose another course : ");
                    else if (stdArr[latestElement].Course2_ID > 10)
                        printf("Input Value exceeding Maximum Value , please enter a value between 1 and 10 : ");
                    scanf("%u", &(stdArr[latestElement].Course2_ID));
                }
                printf("\n => Course (%i) Grade : ", l_counter);
                scanf("%u", &(stdArr[latestElement].Course2_grade));
                fflush(stdin);
                (courseArr[(stdArr[latestElement].Course2_ID) - 1].StudentsNum)++;
                break;
            case 3:
                scanf("%u", &(stdArr[latestElement].Course3_ID));
                fflush(stdin);
                while (((courseArr[(stdArr[latestElement].Course3_ID) - 1].StudentsNum) == MAXCOURSENUM) || ((stdArr[latestElement].Course2_ID) == (stdArr[latestElement].Course3_ID)) || ((stdArr[latestElement].Course3_ID) == (stdArr[latestElement].Course1_ID)) || (stdArr[latestElement].Course3_ID > 10))
                {
                    if ((courseArr[(stdArr[latestElement].Course3_ID) - 1].StudentsNum) == MAXCOURSENUM)
                        printf("The course reached the max number of enrolled students, please choose another course : ");
                    else if (((stdArr[latestElement].Course3_ID) == (stdArr[latestElement].Course2_ID)) || ((stdArr[latestElement].Course3_ID) == (stdArr[latestElement].Course1_ID)))
                        printf("Error !! Duplicate Value , please choose another course : ");
                    else if (stdArr[latestElement].Course3_ID > 10)
                        printf("Input Value exceeding Maximum Value , please enter a value between 1 and 10 : ");
                    scanf("%u", &(stdArr[latestElement].Course3_ID));
                }
                printf("\n => Course (%i) Grade : ", l_counter);
                scanf("%u", &(stdArr[latestElement].Course3_grade));
                fflush(stdin);
                (courseArr[(stdArr[latestElement].Course3_ID) - 1].StudentsNum)++;
                break;
            default:;
            }
        }
        SelectionSort();
        retVal = true;
    }
    return retVal;
}
/**
 * @brief Deletes the students data
 * @param id : the value used to delete the data
 * @return
 */
void SDB_DeleteEntry(uint32 id) // Don't forget to check this function
{
    uint8 index = 0;
    uint8 length = SDB_GetUsedSize();
    if (true == SDB_IsIdExist(id, &index))
    {
        if (MINCOURSENUM >= length)
        {
            printf("Number of Students reached minimum number, The ID student can't be deleted");
        }
        else
        {
            if (((courseArr[stdArr[index].Course1_ID - 1].StudentsNum) <= MINCOURSENUM) || ((courseArr[stdArr[index].Course2_ID - 1].StudentsNum) <= MINCOURSENUM) || ((courseArr[stdArr[index].Course3_ID - 1].StudentsNum) <= MINCOURSENUM))
            {
                printf("The Minimum number of enrolled student a course can't be exceeded !!");
            }
            else
            {
                Swap(&(stdArr[index]),&(stdArr[length - 1]));
                stdArr[length - 1].Student_ID = ~(0);
                stdArr[length - 1].Student_year = 0;
                (courseArr[stdArr[length - 1].Course1_ID - 1].StudentsNum)--;
                (courseArr[stdArr[length - 1].Course2_ID - 1].StudentsNum)--;
                (courseArr[stdArr[length - 1].Course3_ID - 1].StudentsNum)--;
                stdArr[length - 1].Course1_ID = 0;
                stdArr[length - 1].Course2_ID = 0;
                stdArr[length - 1].Course3_ID = 0;
                stdArr[length - 1].Course1_grade = 0;
                stdArr[length - 1].Course2_grade = 0;
                stdArr[length - 1].Course3_grade = 0;
                SelectionSort();
                printf("The student data has been deleted successfully");
            }
        }
    }
    else
    {
        printf("The ID you requested Doesn't exist");
    }
}

/**
 * @brief prints the student data of certain ID
 * @param id : the value used to search the data
 * @return bool variable (retVal) returns:
 *         true : if the element is deleted
 *         false : if the element is not deleted
 */
bool SDB_ReadEntry(uint32 id)
{
    bool retVal = false;
    uint8 index = 0;
    if (true == SDB_IsIdExist(id, &index))
    {
        printf("The Student data : \n");
        printf("=> student ID : %u \n", stdArr[index].Student_ID);
        printf("=> student year : %u \n", stdArr[index].Student_year);
        printf("=> student Courses : \n");
        printf("  - Course (1) ID : %u  - Grade : %u \n", stdArr[index].Course1_ID, stdArr[index].Course1_grade);
        printf("  - Course (2) ID : %u  - Grade : %u \n", stdArr[index].Course2_ID, stdArr[index].Course2_grade);
        printf("  - Course (3) ID : %u  - Grade : %u \n", stdArr[index].Course3_ID, stdArr[index].Course3_grade);
        retVal = true;
    }
    else
    {
        printf("The ID you searched doesn't exist.\n");
    }

    return retVal;
}

/**
 * @brief gets the IDs in the list
 * @param *count : pointer of number of IDs in the list
 * @param *list : pointer of the ID array
 * @return
 */
void SDB_GetList(uint8 *count, uint32 *list)
{
    uint8 l_counter = 0;
    *count = SDB_GetUsedSize();
    if ((NULL != count) && (NULL != list))
    {
        for (l_counter = 0; l_counter < *count; l_counter++)
        {
            list[l_counter] = stdArr[l_counter].Student_ID;
        }
    }
    else
    { /*Nothing*/
    }
}

/**
 * @brief checks if the student ID exists in the list
 * @param id : the ID student to search for int the list
 * @param *index : pointer to number to pass the index of ID in the list
 * @return bool variable (retVal) returns:
 *         true : if the element is deleted
 *         false : if the element is not deleted
 */
bool SDB_IsIdExist(uint32 id, uint8 *index)
{
    bool retVal = false;
    uint8 start = 0;
    uint8 end = 0;
    if (SDB_GetUsedSize() > 0)
        end = SDB_GetUsedSize() - 1;
    else
        end = SDB_GetUsedSize();
    uint8 middle = 0;
    while (end >= start)
    {
        middle = (end - start) / 2 + start;
        if (stdArr[middle].Student_ID == id)
        {
            *index = middle;
            retVal = true;
            break;
        }
        else if (stdArr[middle].Student_ID > id)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return retVal;
}

/**
 * @brief checks the value whether it's less than a certain value and keeps checking until it has a valid value
 * @param *num    : pointer to the number
 * @param checker : the value the number is checked by
 * @return
 */
static void ValidateValue(uint32 *num, uint32 checker)
{
    while (*num < checker)
    {
        printf("Error !!! Number is less than 1 . please enter a valid value : ");
        scanf("%u", num);
    }
}

/**
 * @brief sorts the student according to the ID
 * @param
 * @return
 */
static void SelectionSort()
{
    uint8 ss_iterator = 0;
    uint8 compareIterator = 0;
    uint8 minimumIndex = 0;
    uint8 length = SDB_GetUsedSize();
    for (ss_iterator = 0; ss_iterator < length - 1; ss_iterator++)
    {
        minimumIndex = ss_iterator;
        for (compareIterator = ss_iterator + 1; compareIterator < length; compareIterator++)
        {
            if (stdArr[compareIterator].Student_ID < stdArr[minimumIndex].Student_ID)
            {
                minimumIndex = compareIterator;
            }
        }
        Swap(&(stdArr[minimumIndex]), &(stdArr[ss_iterator]));
    }
}

/**
 * @brief swaps two numbers
 * @param (*num1) : pointer to first number
 * @param (*num2) : pointer to the second number
 * @return
 */
static void Swap(student *num1, student *num2)
{
    student temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}