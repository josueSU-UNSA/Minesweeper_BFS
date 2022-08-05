#include<iostream>
#include<random>
#include <iomanip>
#include<queue>
#include<list>
using namespace std;
// Grafo
// G=(V,E)
// ()

// Mina => label=X; 
// else label=number_of_mines_near;
class Vertex;
class Edge{
    public:
        // Vertex* m_node_1;
        Vertex* m_node;
        int *m_lenght;
    public:
        Edge(){
            // this->m_node_1=0;
            this->m_node=0;
            this->m_lenght=0;
        }
        Edge(Vertex *node,int length){
            // this->m_node_1=node_1;
            this->m_node=node;
            this->m_lenght=new int(length);
        }
};
class Vertex{
    public:
        int *m_ID;
        char *m_label;
        bool m_state_show;//member to show the node in our matrix of minesweeper
        list<Edge*> m_Nodes_adjacency;


    public:
        Vertex(){
            this->m_ID=0;
            this->m_label=new char('_');
        }
        Vertex(int ID){
            this->m_ID=new int(ID);
            this-> m_state_show=false;
            this->m_label=new char('_');
        }
        Vertex(char label){
            this->m_label=new char(label);
            this->m_state_show=false;
            this->m_label=new char('_');
        }
        int number_of_mines_per_no_mine(){
            int count=0;
            auto it=this->m_Nodes_adjacency.begin();
            for(;it!=this->m_Nodes_adjacency.end();it++){
                if(*((*it)->m_node->m_label)=='X')count++;
            }
            return count;
        }

        
};


class Graph{
    public:
        list<Vertex*>m_adjaceny_list;
        int m_num_column_minesweeper;
        int m_num_rows_minesweeper;
    public:
        Graph(){
            this->m_num_column_minesweeper=0;
            this->m_num_rows_minesweeper=0;
        }
        Vertex* look_for_Node(int ID_1){
            Vertex *aux=0;
            // Vertex *aux_2=0;
            auto it=this->m_adjaceny_list.begin();
            for(;it!=this->m_adjaceny_list.end();it++){
                if(*((*it)->m_ID)==ID_1)aux=(*it);
                // if(*((*it)->m_ID)==ID_2)aux_2=(*it);
            }
            if(!aux){
                cout<<"Vertex not found\n";
                return 0;
            }
            return aux;
            
        }
        void insert_Node(int ID){
            m_adjaceny_list.push_back(new Vertex(ID));
        }
        void insert_Edge(int ID_1,int ID_2,int lenght_edge){
            Vertex *aux=0;
            Vertex *aux_2=0;
            auto it=this->m_adjaceny_list.begin();
            for(;it!=this->m_adjaceny_list.end();it++){
                if(*((*it)->m_ID)==ID_1)aux=(*it);
                if(*((*it)->m_ID)==ID_2)aux_2=(*it);
            }
            if(!aux || !aux_2){
                // cout<<"Edge not inserted because one of the IDs isnt made\n";
                return;
            }
            aux->m_Nodes_adjacency.push_back(new Edge(aux_2,lenght_edge));

        }
        void print_Adjacency_list(){
            cout<<"Nodes:\t(Nodes_destiny,length)\n";
            auto it=this->m_adjaceny_list.begin();
            for(;it!=this->m_adjaceny_list.end();it++){
                cout<<*((*it)->m_ID)<<" -> ";
                auto it_2=(*it)->m_Nodes_adjacency.begin();
                for(;it_2!=(*it)->m_Nodes_adjacency.end();it_2++){
                    cout<<"("<<*((*(it_2))->m_node->m_ID)<<" , "<<*((*it_2)->m_lenght)<<") -> ";
                }
                cout<<endl;
            }
        }
        void print_Adjacency_matrix(){
            int size=this->m_adjaceny_list.size();
            // Vertex *aux=0;
            // Vertex *aux_2=0;
            int size_in_matrix=INT_MAX;
            auto it=this->m_adjaceny_list.begin();
            cout<<setw(10);
            for(;it!=this->m_adjaceny_list.end();it++){
                cout<<*((*it)->m_ID)<<setw(5);
            }
            cout<<endl;
            it=this->m_adjaceny_list.begin();
            for(;it!=this->m_adjaceny_list.end();it++){
                cout<<*((*it)->m_ID)<<setw(5);
                for(auto it_3=this->m_adjaceny_list.begin();it_3!=this->m_adjaceny_list.end();it_3++){
                    for(auto it_2=(*it)->m_Nodes_adjacency.begin();it_2!=(*it)->m_Nodes_adjacency.end();it_2++){
                        if(*(((*it_2)->m_node)->m_ID)==*((*it_3)->m_ID)){
                            size_in_matrix=*((*it_2)->m_lenght);
                            // cout<<*((*it_2)->m_lenght)<<setw(2);
                            break;
                        }
                    }
                    if(size_in_matrix==INT_MAX)cout<<"INF"<<setw(5);
                    else cout<<size_in_matrix<<setw(5);
                    size_in_matrix=INT_MAX;
                }
                cout<<endl;
            }
            
        }

        // void print_Adjacency_matrix(){
        //     int size=this->m_adjaceny_list.size();
        //     // Vertex *aux=0;
        //     // Vertex *aux_2=0;
        //     int size_in_matrix=INT_MAX;
        //     auto it=this->m_adjaceny_list.begin();
        //     cout<<setw(10);
        //     for(;it!=this->m_adjaceny_list.end();it++){
        //         cout<<*((*it)->m_ID)<<setw(5);
        //     }
        //     cout<<endl;
        //     it=this->m_adjaceny_list.begin();
        //     for(;it!=this->m_adjaceny_list.end();it++){
        //         cout<<*((*it)->m_ID)<<setw(5);
        //         for(auto it_3=this->m_adjaceny_list.begin();it_3!=this->m_adjaceny_list.end();it_3++){
        //             for(auto it_2=(*it)->m_Nodes_adjacency.begin();it_2!=(*it)->m_Nodes_adjacency.end();it_2++){
        //                 if(*(((*it_2)->m_node)->m_ID)==*((*it_3)->m_ID)){
        //                     size_in_matrix=*((*it_2)->m_lenght);
        //                     // cout<<*((*it_2)->m_lenght)<<setw(2);
        //                     break;
        //                 }
        //             }
        //             if(size_in_matrix==INT_MAX)cout<<"INF"<<setw(5);
        //             else cout<<size_in_matrix<<setw(5);
        //             size_in_matrix=INT_MAX;
        //         }
        //         cout<<endl;
        //     }
            
        // }

        int ** get_Adjacency_matrix(){
            int size=this->m_adjaceny_list.size();
            int **Adjacency_matrix=0;
            if(!size)return 0;
            Adjacency_matrix=new int*[size];
            for(int i=0;i<size;i++)Adjacency_matrix[i]=new int[size];
            
            
            int size_in_matrix=INT_MAX;
            
            auto it=this->m_adjaceny_list.begin();

            it=this->m_adjaceny_list.begin();
            int i=0;
            for(;it!=this->m_adjaceny_list.end();it++){
                
                int j=0;
                for(auto it_3=this->m_adjaceny_list.begin();it_3!=this->m_adjaceny_list.end();it_3++){
                    

                    for(auto it_2=(*it)->m_Nodes_adjacency.begin();it_2!=(*it)->m_Nodes_adjacency.end();it_2++){
                        if(*(((*it_2)->m_node)->m_ID)==*((*it_3)->m_ID)){
                            size_in_matrix=*((*it_2)->m_lenght);
                            
                            break;
                        }
                    }
                    
                    if(size_in_matrix==INT_MAX)Adjacency_matrix[i][j]=INT_MAX;
                    else Adjacency_matrix[i][j]=size_in_matrix;
                    
                    size_in_matrix=INT_MAX;
                    // Adjacency_matrix[i][j]=INT_MAX;
                    j++;
                }
                i++;

            }
            




            return Adjacency_matrix;
        }
        void make_full_connected_table_minesweeper(int n_rows,int n_columns){
            this->m_num_column_minesweeper=n_columns;
            this->m_num_rows_minesweeper=n_rows;
            int counter=1;
            // Insertion of nodes
            for(int r=1;r<=n_rows;r++){
                for(int c=1;c<=n_columns;c++){
                    this->insert_Node(counter++);
                    
                }

            }
            // Connection of the nodes in a table doouble input shape
            counter=1;
            for(int r=1;r<=n_rows;r++){
                for(int c=1;c<=n_columns;c++){
                    // Connection with uppeer node UP
                    this->insert_Edge(counter,counter-n_columns,1);
                    // Connection with lower node DOWN
                    this->insert_Edge(counter,counter+n_columns,1);
                    
                    // Connection with node to RIGHT
                    // Connection with node to RIGHT CORNER UPPER
                    // Connection with node to RIGHT CORNER LOWER
                    if(counter%n_columns!=0){
                        this->insert_Edge(counter,counter+1,1);
                        this->insert_Edge(counter,counter-n_columns+1,1);
                        this->insert_Edge(counter,counter+n_columns+1,1);
                    }
                    
                    // Connection with node to LEFT
                    // Connection with node to LEFT CORNER UPPER
                    // Connection with node to LEFT CORNER LOWER
                    if(counter%n_columns!=1){
                        this->insert_Edge(counter,counter-1,1);
                        this->insert_Edge(counter,counter-n_columns-1,1);
                        this->insert_Edge(counter,counter+n_columns-1,1);
                    }
                    
                    counter++;
                    
                }

            }
            
            // mines location
            
            int  number_mines=10;
            Vertex *aux=0;
            
            srand(time(0));
            for(int i=0;i<number_mines;i++){
                aux=look_for_Node(rand()%(n_columns*n_rows)+1);
                aux->m_label=new char('X');
                
            }
            
            
            // After the mine location we have to look for the nodes 
            // Adjacent nodes and change their  label with the number of mines
            Vertex* aux_2=0;
            counter=1;
            for(int r=1;r<=n_rows;r++){
                for(int c=1;c<=n_columns;c++){
                    aux_2=look_for_Node(counter);
                    char aux_is_mine=*(aux_2->m_label);
                    int aux_mines_number=aux_2->number_of_mines_per_no_mine();
                    char *aux_mines_number_to_char=new char(aux_mines_number+'0');
                    if(aux_is_mine!='X'){
                        // 
                        
                        if(aux_mines_number){
                        //     char *mines=new char(aux_2->number_of_mines_per_no_mine()+'0');
                            aux_2->m_label=aux_mines_number_to_char;
                            // cout<<"Number of X"<<aux_mines_number<<" ";
                        }
                        // cout<<aux_2->number_of_mines_per_no_mine()<<" ";
                        
                    }
                    counter++;
                }

            }
            return;
            // return;
            
            




        }

        void print_Table_minesweeper(){
           
            int counter=1;
            Vertex* aux=0;
            for(int i=0;i<this->m_num_rows_minesweeper;i++){
                for(int j=0;j<this->m_num_column_minesweeper;j++){
                    aux=look_for_Node(counter);
                    cout<<*(aux->m_label)<<" ";       
                    counter++;
                }
                cout<<endl;
            }
            
        }
        

};

int main(){
    
   
    Graph grafo;

    grafo.make_full_connected_table_minesweeper(10,10);
    // grafo.print_Adjacency_list();
    // grafo.print_Adjacency_matrix();
    grafo.print_Table_minesweeper();
    // for(int i=0;i<5;i++){
    //     grafo.insert_Node(i);
    //     // cout<<i<<endl;
    // }
    
    // grafo.insert_Edge(0,1,15);
    // grafo.insert_Edge(1,0,20);
    // grafo.insert_Edge(1,2,0);
    // grafo.insert_Edge(2,1,0);
    // grafo.insert_Edge(2,3,0);
    // grafo.insert_Edge(3,2,0);
    // grafo.insert_Edge(1,3,0);
    // grafo.insert_Edge(3,1,0);
    // grafo.insert_Edge(1,4,0);
    // grafo.insert_Edge(4,1,0);
    // grafo.insert_Edge(3,4,0);
    // grafo.insert_Edge(4,3,0);
    // grafo.insert_Edge(0,4,0);
    // grafo.insert_Edge(4,0,0);
    
    // grafo.print_Adjacency_list();
    // grafo.print_Adjacency_matrix();
    // cout<<"It's done\n";
    // Graph grafo_2;
    // for(int i=1;i<=6;i++){
    //     grafo_2.insert_Node(i);
    //     // cout<<i<<endl;
    // }
    // grafo_2.insert_Edge(1,2,0);
    // grafo_2.insert_Edge(1,4,0);
    // grafo_2.insert_Edge(2,5,0);
    // grafo_2.insert_Edge(4,2,0);
    // grafo_2.insert_Edge(5,4,0);
    // grafo_2.insert_Edge(3,5,0);
    // grafo_2.insert_Edge(3,6,0);
    // grafo_2.insert_Edge(6,6,0);
    // grafo_2.print_Adjacency_list();
    // grafo_2.print_Adjacency_matrix();
    // int **matriz_de_Adyacencia_de_grafo_2=grafo_2.get_Adjacency_matrix();
    // cout<<"Matriz de adyacencia en una matriz externa a la clase\n";
    // grafo_2.get_Adjacency_matrix();
    // int size=grafo_2.m_adjaceny_list.size();
    // cout<<setw(15);
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<size;j++){
    //         cout<<matriz_de_Adyacencia_de_grafo_2[i][j]<<setw(15);
    //     }
    //     cout<<endl;
    // }

    return 0;
}