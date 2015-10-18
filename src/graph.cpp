#include "graph.h"


Graph::Graph(GraphContainer *gc) : container(gc)
{
    if(container == NULL)  //by default -> use an adjacency matrix
    {
        container = new AdjacencyMatrix;
    }
}

Graph::~Graph()
{
    delete container;
}


//------------------------------------------------------------------

void Graph::addNode(const QString& label, float x, float y, float radius, float border, const QString& color)
{
    //nodes.push_back(Node(label, x, y, radius, border, color));
}

void Graph::addEdge(Node *n1, Node *n2, bool oriented, const QString &color)
{
    //edges.push_back(Edge(n1, n2, oriented, color));

}



void Graph::draw(QGraphicsScene& scene)
{
    for(int i = 0; i < nodes.size(); ++i)
    {
        scene.addItem(&nodes[i]->getNode2D());
    }
    for(int i = 0; i < edges.size(); ++i)
    {
        scene.addItem(&edges[i]->getEdge2D());
    }
}


//--------------------------------------------------------------



bool Graph::addNode(Node *node)
{
    if(!container->addNode(node))
        return false;   //insert in container failed
    nodes.push_back(node);
    return true;
}

bool Graph::removeNode(Node *node)
{
    if(!container->removeNode(node))
        return false;   //remove from container failed
    std::vector<Node*>::iterator pos = std::find(nodes.begin(),nodes.end(),node);
    nodes.erase(pos);
    return true;
}

bool Graph::addEdge(Edge *edge)
{
    if(!container->addEdge(edge))
        return false;   //insert in container failed
    edges.push_back(edge);
    return true;
}

bool Graph::removeEdge(Edge *edge)
{
    if(!container->removeEdge(edge))
        return false;   //remove from container failed
    std::vector<Edge*>::iterator pos = std::find(edges.begin(),edges.end(),edge);
    edges.erase(pos);
    return true;
}

QString Graph::toString() const
{
    // rajouter affichage des attributs du graphe
    if(container)
        return container->toString();
    else
        return "vide";
}
std::ostream& operator<<(std::ostream& os, Graph& g)
{
    os << "====== Graph =====\n\n";
    os << g.toString().toStdString() << std::endl;
    return os;
}
