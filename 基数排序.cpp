//2022.6.13
//��������

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand( (unsigned)time(NULL) );

    const int length = 20;
    int arrToSort[length];

    for( int i=0; i<length; i++){
        arrToSort[i] = rand()%10000 / 1 ;     //ȡ��
    }


    //��һ�����ҳ��������ֵ���ж�Ҫ���м��λ�������
    int max = arrToSort[0];
    int bucket[10][length];     //Ͱ��һ����ά����
    int base=1;                     //������
    int bucketIndex[10] = {0};      //�±�Ͱ,���ڼ�¼��ӦͰ�е�Ԫ�ظ���

    for( int i=1; i<length; i++ ){
        max = arrToSort[i] > max ? arrToSort[i] : max;
    }

    //�ڶ�����ѭ�����ֵ��λ���Σ���������Ϊ����ѭ�����ٴ�
    while( max > 0){
        //����ԭ���飬�����ά����Ͱ��
        for( int i=0; i<length; i++){
            //ÿ��ѭ������������ֵĸ�λ(ʮλ����λ��)�������ӦͰ��
            int temp = arrToSort[i] / base % 10;

            //eg,152����һ��ѭ��252�����1��Ͱ���ڶ���ѭ�������4��Ͱ����3��ѭ�������1��Ͱ
            bucket[temp][bucketIndex[temp]] = arrToSort[i];
            bucketIndex[temp]++;            //��Ӧ�±�Ͱ��¼��Ԫ�ظ�����1
        }

        //һ�λ��������������Ͱ�е��������¸�ֵ��ԭʼ���飬����±�Ͱ
        int index = 0;
        for( int i=0; i<10; i++){
            if( bucketIndex[i] != 0 ){              //����±�Ͱ�м�¼��Ԫ�ظ�����Ϊ0��ȡ������ֵ��ԭ����
                for( int j=0; j<bucketIndex[i]; j++){
                    arrToSort[index++] = bucket[i][j];
                }
            }
        }

        for( int i=0; i<10; i++){
            bucketIndex[i] = 0;
        }

        base *= 10;      //����ǰ��һλ���Ӹ�λ-��ʮλ-����λ...
        max /= 10;      //���ֵ��һλ
    }

    for( int i=0; i<length; i++){
        printf("%d\t",arrToSort[i]);
        (i+1)%10 ? printf("") : printf("\n");

    }
    printf("\n");

    return 0;
}





