# include <stdio.h>
# include <conio.h>

struct node{
	int set; /* Attribute to indicate which connection the node belongs to */
} node[100];

struct edge {
	int first_node,second_node;
	int distance;   /* Distance between the nodes */
	int selected;   /* To denote whether edge is selected */
} e[100];

int edge_count=0;

void getdata(int index,int total)  /* Function to input the distances */
{
	
	for (int i=index;i<total;++i)
	{
		if (i!=index)
		{
			printf("Enter distance between vertex %c and %c : ",index+65,i+65);
			scanf("%d",&e[edge_count].distance);
			e[edge_count].first_node=index;
			e[edge_count].second_node=i;
			++edge_count;
		}
	}
}


Void initialise(int total_nodes)
{
	
	for (int i=0;i<total_nodes;++i)
		node[i].set = i;     /* Set number to indicate loop */
	for (int i=0;i<edge_count;++i)
		e[i].selected=-1;    /* Edge not selected initially */
}
Void sort_edges()
{
	int i,j;
    struct edge temp;
	for (i=0;i<edge_count-1;++i){ /* Sorting by Bubble Sort */
		for (j=0;j<edge_count-i-1;++j){
			if (e[j].distance>e[j+1].distance) {
				temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
		    }
        }
    }
}

void main()
{
	int total_vertices,i,j,k,m,n,edges_selected=0,nodel,noder;
	printf("Enter the number of vertices : ");
	scanf("%d",&total_vertices);

	for (i=0;i<total_vertices;++i)
		getdata(i,total_vertices);

	initialise(total_vertices);   /* Initialising all nodes and edges */
	sort_edges();


	/* Printing sorted order of the edges */
	
	printf("Sorted order of edges : ");
	for (i=0;i<edge_count;++i)
		printf("\nEdge : %d    First Node : %c     Second Node : %c    Distance : %d",i,e[i].first_node+65,e[i].second_node+65,e[i].distance);

	/* Finding the minimum spanning tree */

	int i=0;   /* Initialise i to beginning of the edge array */
	do
	{
		e[i].selected=1;   /* Edge is selected */
		nodel=e[i].first_node;    /* Node on the left of the edge */
		noder=e[i].second_node;   /* Node on the right of the edge */

		/* If the set is the same do not select that edge */
		if (node[nodel].set==node[noder].set)
			e[i].selected=-1;     /* Deselect the edge */
		else
		{
            edges_selected++;     /* Select the edge */
			m=node[nodel].set;
			k=node[noder].set;
			for (n=0;n<total_vertices;++n)   
			{
				/* Making all connected nodes of the same set */
				if (node[n].set==k)
					node[n].set=m;
			}
		}
		++i;
	}
	while(edges_selected<(total_vertices-1));/*Check till total_nodes-1 edges are formed*/
	printf("\n\n\nMinimal Spanning Tree : \n");/*Printing the minimum spanning tree */
	for (i=0;i<edge_count;++i)
	if (e[i].selected==1)
	printf("\n%c<---->%cDistance: %d",e[i].first_node+65,e[i].second_node+65,e[i].distance);
	getch();
}
