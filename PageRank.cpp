#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <random>
#include <vector>
#define MAX_VTS 3000
//정점에 대한 정보
class Node{
    protected:
        std::string name;
        std::string id;
    public:
        Node(){name="";id="";}
        Node(std::string ID, std::string thename):name(thename),id(ID){}
        ~Node(){}
        std::string getid(){return id;}
        std::string getname(){return name;}


};
//인접 행렬로 그래프를 저장
    class AdjMatGraph{
    protected:
    //노드의 개수
        int size; 
        Node *vertices; //정점의 배열
        int **adj;    //인접행렬
        Node* node;   //정점

    public:
        AdjMatGraph(){ 
            vertices= new Node[MAX_VTS];
            adj=new int*[MAX_VTS];
            for(int i=0;i<MAX_VTS;i++){
                adj[i]=new int[MAX_VTS];
            }
            reset(); }
        ~AdjMatGraph(){}

        Node getVertex(int i){ return vertices[i]; }
        int getEdge(int i, int j) { return adj[i][j]; }
        void setEdge(int i, int j, int val) { 
        adj[i][j] = val;}
        bool isEmpty(){ return size==0; }
        bool isFull(){ return size>=MAX_VTS; }

        void reset(){
            size=0;
            for(int i=0 ; i<MAX_VTS ; i++){
                for(int j=0 ; j<MAX_VTS ; j++){
                    setEdge(i,j,0);
                }
            }
        }
       //정점삽입함수
       //정점배열 vertices에 정점 삽입하고 노드의 개수를 1씩 늘린다.
        void insertVertex(Node node){
            if(!isFull()){ vertices[size]=node;size+=1;}
            else { std::cout << "Exceeding maximum number of vertices"; } 
        }
        //가중치가 있는 그래프 간선 저장을 위하여 파일로부터 읽어들이는 함수
        void WloadEdge(std::string filename,int num){
            std::ifstream ifs;
            //파일을 읽어온다.
            ifs.open(filename);
            if(ifs.fail()){
                std::cout<<"Input file opening failed\n";
                exit(1);
            }
            std::cout<<filename<<" opened successfully.\n";
            std::cout<<"Saving graph...Please wait.\n";
            std::string line;
            std::getline(ifs, line);
            std::string v1;
            std::string v2;
            std::string weight;
            int w;
            
            while(ifs.peek()!=EOF){
                std::stringstream ss;
                char next[1000];
                //한줄씩 읽고, 각 줄을 /t단위로 세 부분으로 끊어서 저장
                std::getline(ifs, line);
                strcpy(next,line.c_str());
                //처음 부분: SourceNode
                v1=strtok(next,"\t");
                //두번째 부분: TargetNode
                v2=strtok(NULL,"\t");
                //마지막 부분: Weight
                weight=strtok(NULL,"\n");
                ss<<weight;
                ss>>w;
                int i, j;
                //읽어들인 SourceNode의 ID와 
                //정점의 배열(vertices)에 있는 정점 중 ID가 일치하는 vertices의인덱스 찾기(i)
               for(i=0;i<size;i++){
                   if(vertices[i].getid()==v1){
                   break;}
               }
                //읽어들인 TargetNode의 ID와 
                //정점의 배열(vertices)에 있는 정점 중 ID가 일치하는 vertices의인덱스 찾기(j)
               for(j=0;j<size;j++){
                   if(vertices[j].getid()==v2){
                       break;
                   }
                   
               }
               //찾은 인덱스를 바탕으로 가중치가 있는 그래프의 간선삽입함수 호출
               //num==0이면 방향성이 없는그래프의 간선 삽입
               //다른 수이면 방향성이 있는 그래프의 간선 삽입
               if(num==0){
               WinsertEdge(i,j,w,0);}
               else{
                   WinsertEdge(i,j,w,1);
               }

            }
            std::cout<<"Graph saved successfully.\n";
            ifs.close();
            
        };
        //가중치가 없는 그래프 간선 저장을 위하여 파일로부터 읽어들이는 함수
        void nWloadEdge(std::string filename,int num){
            //파일을 읽어온다.
            std::ifstream ifs;
            ifs.open(filename);
            if(ifs.fail()){
                std::cout<<"Input file opening failed\n";
                exit(1);
            }
            std::cout<<filename<<" opened successfully.\n";
            std::cout<<"Saving graph...Please wait.\n";
            std::string line;
            std::getline(ifs, line);
            std::string v1;
            std::string v2;
            std::string weight;
            while(ifs.peek()!=EOF){
                char next[1000];
                //한줄씩 읽고, 각 줄을 /t단위로 세 부분으로 끊어서 저장
                std::getline(ifs, line);
                strcpy(next,line.c_str());
                 //처음 부분: SourceNode
                v1=strtok(next,"\t");
                //두번째 부분: TargetNode
                v2=strtok(NULL,"\t");
                //마지막 부분: Weight
                weight=strtok(NULL,"\n");
                int i, j;
                //읽어들인 SourceNode의 ID와 
                //정점의 배열(vertices)에 있는 정점 중 ID가 일치하는 vertices의인덱스 찾기(i)
               for(i=0;i<size;i++){
                   if(vertices[i].getid()==v1){
                   break;}
               }
               //읽어들인 TargetNode의 ID와 
                //정점의 배열(vertices)에 있는 정점 중 ID가 일치하는 vertices의인덱스 찾기(j)
               for(j=0;j<size;j++){
                   if(vertices[j].getid()==v2){
                       break;
                   }
                   
               }
             //찾은 인덱스를 바탕으로 가중치가 없는 그래프의 간선삽입함수 호출
               //num==0이면 방향성이 없는그래프의 간선 삽입
               //다른 수이면 방향성이 있는 그래프의 간선 삽입
               if(num==0){
               nWinsertEdge(i,j,0);}
               else{nWinsertEdge(i,j,1);}
            }
            std::cout<<"Graph saved successfully.\n";
            ifs.close();
        }
        //가중치가 있는 그래프의 간선삽입함수
        void WinsertEdge(int u, int v, int w,int num){
            if(u < 0 || u >=MAX_VTS){
                std::cout << "out of range";
                exit(0);
            }
            //num==0이면 방향성이 없는그래프의 간선 삽입
            if(num==0){
            setEdge(u, v, w);
            setEdge(v, u, w);}
            else{
                //다른 수이면 방향성이 있는 그래프의 간선 삽입
                setEdge(u,v,w);
            }
        }
       //가중치가 없는 그래프의 간선삽입함수
        void nWinsertEdge(int u, int v,int num){
            if(u < 0 || u >=MAX_VTS){
                std::cout << "out of range";
                exit(0);
            }
            //num==0이면 방향성이 없는그래프의 간선 삽입
            if(num==0)
            {setEdge(u, v, 1);
            setEdge(v, u, 1);}
            else{
                //다른 수이면 방향성이 있는 그래프의 간선 삽입
                setEdge(u,v,1);
            }
        }

        void display(){
            for(int i=0 ; i<size; i++){
                for(int j=0;j<size;j++){
                    if(getEdge(i,j)!=0){
                        std::cout<<"I: "<<i<<" J: "<<j<<" Edge[i][j]:"<<adj[i][j]<<"\n";
                    }
                }
        }}
        //그래프의 정점 저장을 위하여 파일로부터 읽어들이는 함수
        void loadNames(std::string filename){
            std::ifstream ifs;
            ifs.open(filename);
            if(ifs.fail()){
                std::cout<<"Input file opening failed\n";
                exit(1);
            }
            std::cout<<filename<<" opened successfully.\n";
            std::string line;
            std::getline(ifs, line);
            std::string id;
            std::string name;
            while(ifs.peek()!=EOF){
                char next[1000];
                //한줄씩 읽고, 각 줄을 /t단위로 두 부분으로 끊어서 저장
                std::getline(ifs, line);
                strcpy(next,line.c_str());
                //첫번째부분: ID
                id=strtok(next,"\t");
                //두번째부분: 정점의 이름
                name=strtok(NULL,"\n");
                Node n(id,name);
                //정점삽입함수 호출
                insertVertex(n);
        

            }
            ifs.close();

        }
        int getSize(){
            return size;}
        void printVertex(){
            for(int i=0;i<size;i++){
                std::cout<<vertices[i].getname()<<"\n";
            }
        }
         
        
        
};
//가중치가 없는 그래프에서의 random walker
class NWRandom_walker{
 protected:
        int pos;
        int size;
        AdjMatGraph adj;
        double *visitnum;
        int n;
        double q;
        int p;
    public:
    //파라미터로 시작점, 임의의 노드로 점프할 확률 q, 인접행렬, walking length n을 입력받는다.
    NWRandom_walker(int pos1,double pr, AdjMatGraph ad,int length):pos(pos1),adj(ad),n(length),q(pr){
        //인접행렬의 정점의 개수를 불러와서 저장한다.
        size=adj.getSize();
        //random walker가 전체 정점에 방문한 횟수를 저장하는 배열
        visitnum=new double[size];
        for(int i=0;i<size;i++){
            visitnum[i]=0;   }
        //확률에 따라 점프나 이웃 노드로의 이동을 수월하게 하기 위하여 q에 100을 곱한다.
        p=q*100;    
        }
        int getPos(){return pos;}
        ~NWRandom_walker(){}
        //random walker의 이동
        void Move(){
            std::cout<<"The Random Walker starts the move.\n";
            //시작점의 노드의 방문횟수 1증가
            visitnum[pos]=1;
            std::random_device rd;
            std::mt19937 gen(rd());
            for(int i=0;i<n;i++){
            //0~99사이의 값 중 하나 고른다. 
            std::uniform_int_distribution<int> dist1 (0,100-1);
            int randnum=dist1(gen);
            //고른 값이 q에 100을 곱한 값인 p보다 같거나 크면
            //1-q의 확률이 된 것으로, 이웃 노드를 탐색
            if(randnum>=p){
                //이웃 노드를 저장할 벡터 선언
                std::vector<int> v;
                for(int k=0;k<=size;k++){
                    //정점의 간선이 존재하면(1이면)
                    if (adj.getEdge(pos,k)!=0){
                        //벡터에 삽입
                        v.push_back(k);}}
                        int s=v.size();
                        //이웃 노드가 있을 경우
                        if (s!=0){
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        //이웃 노드 중 하나 선택
                        std::uniform_int_distribution<int> dist2 (0,s-1);
                        int randnum=dist2(gen);
                        //이동 후 방문횟수 증가
                        pos=v[randnum];
                        visitnum[pos]++;}
                    else{
                        int rand;
                        //우선 방문횟수 증가
                        visitnum[pos]++;
                        //탈출할 임의의 노드 선정
                        while(1){
                            std::random_device rd;
                            std::mt19937 gen(rd());
                             std::uniform_int_distribution<int> dist1 (0,size-1);
                            rand=dist1(gen);
                            if(rand!=pos){
                                break;
                            }
                        }
                        i++;
                        //선정된 노드로 이동 후 방문횟수 증가
                        pos=rand;
                        visitnum[pos]++;
                    }    }

           //0~99에서 고른 수가 p보다 작으면 q의 확률이 된 것
            else
               {
                   //점프할 임의의 노드 선정
                   std::random_device rd;
                     std::mt19937 gen(rd());

                    std::uniform_int_distribution<int> dist (0,size-1);
                int newpos=dist(gen);
                //선정된 노드로 점프 후 방문횟수 증가
                pos=newpos;
                visitnum[pos]++;
                }          
             }
             std::cout<<"Random Walker has completed the move.\n";}
            
    //pagerank를 계산하는 함수
    void PageRank(){
       std::cout<<"Starts PageRank calculation.\n";
        double sum=0;
              for(int i=0;i<size;i++){
                  //방문횟수/n=노드의 pagerank
                  visitnum[i]=visitnum[i]/(n);
              }
              //전체 노드의 pagerank의 합
              for(int j=0;j<size;j++){
                 sum+=visitnum[j];
              }
              std::cout<<"PageRank calculation completed.\nsum: "<<sum<<"\n";

    }
    //pagerank를 기준으로 내림차순으로 정점을 정렬하는 함수
    void Sort(){
        //정점의 이름이 저장되는 배열
        std::string names[size];
        for(int i=0;i<size;i++){
            //정점의 이름을 저장
            names[i]=adj.getVertex(i).getname();
        }
        std::string temp;  
        double temp2;
        //노드의 pagerank를 비교하여 정점의 이름이 저장된 배열 names를 pagerank의 내림차순으로 정렬
        for(int i=0; i<size; i++) { 
          for(int j=i+1; j<size; j++) { 
                if(visitnum[i]<visitnum[j]) {
                      temp=names[i]; 
                      names[i]=names[j]; 
                      names[j]=temp; 
                      temp2=visitnum[i];
                      visitnum[i]=visitnum[j];
                      visitnum[j]=temp2;
                      } } }
                 //정렬이 끝났으면 pagerank가 큰 노드 10개의 이름 출력     
                std::cout<<"The top 10:\n";
                for(int i=0;i<10;i++){
            std::cout<<names[i]<<"\n";
        }
     }
    void printPageRank(){
        int nonvisit=0;
        int visited=0;
        for(int i=0;i<size;i++){
            if(visitnum[i]==0){
                nonvisit++;
            }
            else{
                visited++;
            }
            std::cout<<"visitnum["<<i<<"]: "<<visitnum[i]<<"\n";

        }
            std::cout<<"Unvisited Node: "<<nonvisit<<"\n";
            std::cout<<"visited Node: "<<visited<<"\n";
 
    }
    




};
//가중치가 있는 그래프에서의 random walker
class WRandom_walker:public NWRandom_walker{
    private:
    //이동할 이웃 노드를 고르기 전 어떠한 노드의 이웃 노드들을 가중치만큼 저장할 배열
        int *prob;
    public:
    //파라미터로 시작점, 임의의 노드로 점프할 확률 q, 인접행렬, walking length n을 입력받는다.
    WRandom_walker(int pos1,double pr, AdjMatGraph ad,int length):NWRandom_walker(pos1,pr,ad,length)
    {  
        prob=new int[MAX_VTS];
    }
           //random walker의 이동
            void Move(){
           std::cout<<"The Random Walker starts the move.\n";
           //시작점의 노드의 방문횟수 1증가
           visitnum[pos]=1;
           std::random_device rd;
           std::mt19937 gen(rd());
            for(int i=0;i<n;i++){
             //0~99사이의 값 중 하나 고른다.
            std::uniform_int_distribution<int> dist1 (0,100-1);
            int randnum=dist1(gen);
            //고른 값이 q에 100을 곱한 값인 p보다 같거나 크면
            //1-q의 확률이 된 것으로, 이웃 노드를 탐색
            if(randnum>=p){
                //이웃노드의 배열의 크기 0으로 초기화(이웃노드 수)
                int probsize=0;
                //이웃노드의 배열 초기화
                for(int i=0;i<size;i++){
                    prob[i]=0;
                }
                //이웃노드들을 탐색 
                //가중치가 0이 아니면 가중치만큼 prob에 이웃노드의 인덱스 삽입
                for(int k=0;k<size;k++){
                    if (adj.getEdge(pos,k)!=0){  
                        for(int l=0;l<adj.getEdge(pos,k);l++){
                            prob[probsize]=k;
                            probsize++;
    
                        }}}
                        //이웃 노드의 수가 0이 아니면
                        if (probsize!=0){
      
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        //이웃노드의 인덱스의 배열에서 하나를 선정
                        std::uniform_int_distribution<int> dist2 (0,probsize-1);
                        int randnum=dist2(gen);
                        //선정된 배열에 해당하는 인덱스의 노드로 이동 후 방문횟수 증가
                        pos=prob[randnum];
                        visitnum[pos]++;}
                    else{
                         int rand;
                        //우선 방문횟수 증가
                        visitnum[pos]++;
                        //탈출할 임의의 노드 선정
                        while(1){
                            std::random_device rd;
                            std::mt19937 gen(rd());
                             std::uniform_int_distribution<int> dist1 (0,size-1);
                            rand=dist1(gen);
                            if(rand!=pos){
                                break;
                            }
                        }
                        i++;
                        //선정된 노드로 이동 후 방문횟수 증가
                        pos=rand;
                        visitnum[pos]++;
                    }
                    }
                        
             //0~99에서 고른 수가 p보다 작으면 q의 확률이 된 것
            else
               {
                   std::random_device rd;
                    std::mt19937 gen(rd());
                //점프할 임의의 노드 선정
                std::uniform_int_distribution<int> dist (0,size-1);
                int newpos=dist(gen);
                //선정된 노드로 점프 후 방문횟수 증가
                pos=newpos;
                visitnum[pos]++;}
                
              }

            } 

            

        };
        



int main(){
    AdjMatGraph ad1;
    //방향성이 없는 그래프의 정점
    ad1.loadNames("starwars-full-interactions-allCharacters-nodes.tsv");
    //방향성이 없고 가중치가 있는 그래프의 간선 삽입
    ad1.WloadEdge("starwars-full-interactions-allCharacters-links.tsv",0);
    //방향성이 없고 가중치가 있는 그래프의 random walker
    WRandom_walker r3(0,0.2,ad1,70000);
    r3.Move();
    r3.PageRank();
    r3.Sort();
    //방향성이 없고 가중치가 없는 그래프의 간선 삽입
    ad1.nWloadEdge("starwars-full-interactions-allCharacters-links.tsv",0);
    //방향성이 없고 가중치가 없는 그래프의 random walker
    NWRandom_walker r4(0,0.2,ad1,70000);
    r4.Move();
    r4.PageRank();
    r4.Sort();

    //방향성이 있는 그래프
    AdjMatGraph adj2;
    //방향성이 있는 그래프의 정점
    adj2.loadNames("station_names.tsv");
    //방향성이 있는 그래프의 간선 삽입
    adj2.WloadEdge("bicycle_trips_all.tsv",1);
    //방향성이 있고 가중치가 있는 그래프의 random walker   
    WRandom_walker r1(0,0.4,adj2,90000); 
    r1.Move();
    r1.PageRank();
    r1.Sort(); 
    //방향성이 있고 가중치가 없는 그래프의 random walker
    adj2.nWloadEdge("bicycle_trips_all.tsv",1); 
    NWRandom_walker r2(0,0.4,adj2,90000); 
    r2.Move();
    r2.PageRank();
    r2.Sort();     
                

    return 0;
}
