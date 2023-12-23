//2022.6.13
//基数排序

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand( (unsigned)time(NULL) );

    const int length = 20;
    int arrToSort[length];

    for( int i=0; i<length; i++){
        arrToSort[i] = rand()%10000 / 1 ;     //取整
    }


    //第一步，找出数组最大值，判断要进行几次基数排序
    int max = arrToSort[0];
    int bucket[10][length];     //桶，一个二维数组
    int base=1;                     //基数。
    int bucketIndex[10] = {0};      //下标桶,用于记录对应桶中的元素个数

    for( int i=1; i<length; i++ ){
        max = arrToSort[i] > max ? arrToSort[i] : max;
    }

    //第二步，循环最大值的位数次，即最大基数为几，循环多少次
    while( max > 0){
        //遍历原数组，放入二维数组桶中
        for( int i=0; i<length; i++){
            //每次循环求出对于数字的个位(十位、百位等)，放入对应桶中
            int temp = arrToSort[i] / base % 10;

            //eg,152，第一次循环252放入第1个桶，第二次循环放入第4个桶，第3次循环放入第1个桶
            bucket[temp][bucketIndex[temp]] = arrToSort[i];
            bucketIndex[temp]++;            //对应下标桶记录的元素个数加1
        }

        //一次基数排序结束，把桶中的数据重新赋值给原始数组，清空下标桶
        int index = 0;
        for( int i=0; i<10; i++){
            if( bucketIndex[i] != 0 ){              //如果下标桶中记录的元素个数不为0，取出并赋值给原数组
                for( int j=0; j<bucketIndex[i]; j++){
                    arrToSort[index++] = bucket[i][j];
                }
            }
        }

        for( int i=0; i<10; i++){
            bucketIndex[i] = 0;
        }

        base *= 10;      //基数前进一位，从个位-》十位-》百位...
        max /= 10;      //最大值退一位
    }

    for( int i=0; i<length; i++){
        printf("%d\t",arrToSort[i]);
        (i+1)%10 ? printf("") : printf("\n");

    }
    printf("\n");

    return 0;
}





