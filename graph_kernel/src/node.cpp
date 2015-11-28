#include "node.h"
#include "edge.h"
#include <stack>
#include <algorithm>

Node::Node(int id) : Element(id)
{


}


bool Node::addAdjacentEdge(Edge *edge)
{
    for(std::vector<Edge*>::iterator it = adjacentEdges.begin(); it != adjacentEdges.end(); ++it)
        if(*it == edge)
            return false; //already stored
    adjacentEdges.push_back(edge);
    if(edge->isOriented())
    {
        if(edge->getNode1() == this)
            adjacentOutEdges.push_back(edge);
        else if(edge->getNode2() == this)
            adjacentInEdges.push_back(edge);
    }
    return true;
}

bool Node::removeAdjacentEdge(Edge *edge)
{
    auto pos = std::find(adjacentEdges.begin(),adjacentEdges.end(),edge);
    if(pos == adjacentEdges.end())
        return false; //edge was not adjacent to this node
    adjacentEdges.erase(pos);
    if(edge->isOriented())
    {
        if(edge->getNode1() == this)
        {
            auto pos2 = std::find(adjacentOutEdges.begin(),adjacentOutEdges.end(),edge);
            if(pos2 != adjacentOutEdges.end())
                adjacentOutEdges.erase(pos2);
        }else if(edge->getNode2() == this)
        {
            auto pos2 = std::find(adjacentInEdges.begin(),adjacentInEdges.end(),edge);
            if(pos2 != adjacentInEdges.end())
                adjacentInEdges.erase(pos2);
        }
    }
    return true;
}

int Node::getDirectSuccessors(std::vector<Node*>& successors) const
{
    int iter=0;
    successors.clear();
    for(;iter<adjacentOutEdges.size();iter++)
    {
        successors.push_back(adjacentOutEdges[iter]->getNode2());
    }
    return iter;
}

int Node::getDirectPredecessors(std::vector<Node*>& predecessors) const
{
    int iter=0;
    predecessors.clear();
    for(;iter<adjacentInEdges.size();iter++)
    {
        predecessors.push_back(adjacentInEdges[iter]->getNode1());
    }
    return iter;
}


int Node::getSuccessors(std::vector<Node *> &successors) const
{   //we use breadth-first search with a stack
    successors.clear();
    std::stack<const Node*> stack;
    stack.push(this);
    std::vector<Node*> childs;
    while(stack.size()>0)
    {
        const Node* current = stack.top();
        stack.pop();
        childs.clear();
        current->getDirectSuccessors(childs);
        for(unsigned int iter=0 ;iter<childs.size(); iter++)
        {
            if(std::find(successors.begin(),successors.end(),childs[iter]) == successors.end())
            {
                successors.push_back(childs[iter]);
                stack.push(childs[iter]);
            }
        }
    }
    return successors.size();
}

int Node::getPredecessors(std::vector<Node *> &predecessors) const
{   //we use breadth-first search with a stack
    predecessors.clear();
    std::stack<const Node*> stack;
    stack.push(this);
    std::vector<Node*> parent;
    while(stack.size()>0)
    {
        const Node *current = stack.top();
        stack.pop();
        parent.clear();
        current->getDirectPredecessors(parent);
        for(unsigned int iter=0; iter<parent.size(); iter++)
        {
            if(std::find(predecessors.begin(), predecessors.end(), parent[iter]) == predecessors.end())
            {
                predecessors.push_back(parent[iter]);
                stack.push(parent[iter]);
            }
        }
    }
    return predecessors.size();
}

