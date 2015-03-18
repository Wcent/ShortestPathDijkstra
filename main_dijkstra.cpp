// dijkstra.cpp 
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int dijkstra(int (*graphy)[8], int vertexs, int s_v, int e_v);

int main()
{
	int g[8][8];
	memset(g, -1, sizeof(int)*8*8);
	g[0][0] = 0, g[1][1] = 0, g[2][2] = 0, g[3][3] = 0;
	g[4][4] = 0, g[5][5] = 0, g[6][6] = 0, g[7][7] = 0;
	g[1][2] = 3, g[2][1] = 3;
	g[1][6] = 1, g[6][1] = 1;
	g[2][3] = 2, g[3][2] = 2;
	g[2][4] = 1, g[4][2] = 1;
	g[3][4] = 3, g[4][3] = 3;
	g[3][5] = 1, g[5][3] = 1;
	g[3][6] = 1, g[6][3] = 1;
	g[3][7] = 3, g[7][3] = 3;
	g[4][5] = 1, g[5][4] = 1;
	g[5][7] = 2, g[7][5] = 2;

	int s = 2;
	int e;
	for(e=1; e<8; e++)
		cout<<"shortest path, from "<<s<<" to "<<e<<" is: "<<dijkstra(g, 8, s, e)<<endl;

	return 0;
}


// ���·����~ Dijkstra, dist[j] = min{dist[j], dist[i]+graphy[i][j]}
// ~ graphy: G = (V, E), V�����㼯, E: �߼�
// ~ e �� E & e > 0��ʾ�����ڽӣ�ȨֵΪe, e = -1��ʾ�����㲻�ڽ�
// ~
int dijkstra(int (*graphy)[8], int vertexs, int s_v, int e_v)
{
	int *dist; //��㵽���յ�����·��
	int *vis;  //�ѷ��ʹ��Ķ���
	int num;
	int min, k;
	
	dist = new int[vertexs];
	vis = new int [vertexs];

	//��ʼ����-1����max_value
	memset(dist, -1, sizeof(int)*vertexs);
	//��㵽�յ���̾���Ϊ0
	dist[s_v] = 0;
	memset(vis, 0, sizeof(int)*vertexs);
	num = vertexs-1;
	while(num)
	{
		//̰�Ĳ��ԣ��ӷ��ʹ��Ķ����У��ҳ����·��������֪�����·����ʼ����
		min = -1;
		k = -1;
		for(int i=0; i<vertexs; i++)
		{
			if(vis[i] != 1 && dist[i] != -1 &&
				(min != -1 && dist[i] < min || min == -1))
			{
				min = dist[i];
				k = i;
			}
		}

		//�յ����·�����ҵ������ж������·�������ҵ�
		if(e_v == k || min == -1)
			break;
		//��Ƿ��ʹ��Ķ���
		vis[k] = 1;
		num--;
		
		//dist[j] = min{d[j], dist[i]+graphy[i][j]}
		//����δ���ʹ��ڽӶ�������·��
		for(i=0; i<vertexs; i++)
		{
			if(vis[i] != 1 && graphy[k][i] != -1 &&
			   (dist[i] != -1 && dist[i] > min + graphy[k][i] || dist[i] == -1))
				dist[i] = min + graphy[k][i];
		}
	}
	min = dist[e_v];
	delete [] dist;
	delete [] vis;
	return min;
}
