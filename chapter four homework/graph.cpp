//
// Created by lcr on 2017/12/7.
//

#include "graph.h"

template <class T>
graph<T>::graph(int vertexNum):vertexNum(vertexNum) {
    edgeNum = 0;
    mark.resize((size_t)vertexNum);
    matrix.resize((size_t) vertexNum);
    for(int i=0;i<vertexNum;i++){
        matrix[i].resize((size_t)vertexNum);
    }
}

template <class T>
graph<T>::~graph()=default;

template <class T>
void graph<T>::setVertexNum(int vertexNum) {
    this->vertexNum = vertexNum;
}

template <class T>
void graph<T>::setEdgeNum(int edgeNum) {
    this->edgeNum = edgeNum;
}

template <class T>
int graph<T>::getVertexNum() {
    return vertexNum;
}

template <class T>
int graph<T>::getEdgeNum() {
    return edgeNum;
}

template <class T>
void graph<T>::setEdge(edge<T> oneEdge,int flag) {
    if(!flag){
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = oneEdge.getWeight();
        matrix[oneEdge.getEnd()][oneEdge.getStart()] = oneEdge.getWeight();
    }
    else{
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = oneEdge.getWeight();
    }
}

template <class T>
int graph<T>::getOneEdgeStart(edge<T> &oneEdge) {
    return oneEdge.getStart();
}

template <class T>
int graph<T>::getOneEdgeEnd(edge<T> &oneEdge) {
    return oneEdge.getEnd();
}

template <class T>
T graph<T>::getOneEdgeWeight(edge<T> &oneEdge) {
    return oneEdge.getWeight();
}

template <class T>
void graph<T>::deleteOneEdge(edge<T> oneEdge, int flag) {
    if(!flag){
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = 0;
        matrix[oneEdge.getEnd()][oneEdge.getStart()] = 0;
    }
    else{
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = 0;
    }
}

template <class T>
void graph<T>::DFSTraverse(vector<int> &m, int num) {
    m[num] = 1;
    cout<<num<<" ";
    for(int i = 0;i<vertexNum;i++){
        if(m[i] == 0&&matrix[num][i] != 0){
            DFSTraverse(m,i);
        }
    }
}

template <class T>
void graph<T>::DFS() {
    for(int i=0;i<vertexNum;i++){
        mark[i] = 0;
    }
    for(int i = 0;i<vertexNum;i++){
        if(mark[i]==0){
            DFSTraverse(mark,i);
        }
    }
    cout<<endl;
}

template <class T>
void graph<T>::BFSTraverse(vector<int> &m, int num) {
    queue<int> vertexQueue;
    int one;
    m[num] = 1;
    cout<<num<<" ";
    vertexQueue.en_queue(num);
    while(vertexQueue.get_size()!=0){
        vertexQueue.de_queue(one);
        for(int i = 0;i<vertexNum;i++){
            if(m[i]==0&&matrix[one][i] != 0){
                vertexQueue.en_queue(i);
                m[i] = 1;
                cout<<i<<" ";
            }
        }
    }
}

template <class T>
void graph<T>::BFS() {
    for(int i=0;i<vertexNum;i++){
        mark[i] = 0;
    }
    for(int i = 0;i<vertexNum;i++){
        if(mark[i]==0){
            BFSTraverse(mark,i);
        }
    }
}

template <class T>
void graph<T>::Prim() {

}