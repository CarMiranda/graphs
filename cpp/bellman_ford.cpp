#include <iostream>
#include <vector>
#include <set>

class Graph;
class Vertex;

class Vertex {
    public:
        Vertex(Graph *graph, std::string label) : {
            this->graph = graph;
            this->label = label;
        };

        ~Vertex() {
            for (std::vector<*Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
                this->graph->removeEdge(*it);
                delete **it;
            }
        };

        std::string getLabel() { return label; };

        void setLabel(std::string label) { this->label = label; };

        void addEdge(Vertex *to, double weight) {
            Edge *e = new Edge(this, to, weight);
            if (std::find(this->edges.begin(), this->edges.end(), e) != this->edges.end()) {
                return;
            }
            if (!loopback && this == to) this->loopback = true;
            this->graph->addEdge(e);
            to->addEdge(e);
            this->edges.push_back(e);
        };

        void addEdge(Edge *e) {
            this->edges.push_back(e);
        };

        std::vector<Vertex> getAdjacents() {
            std::vector<Vertex> adjacents;
            for (std::vector<*Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++it) {
                adjacents.push_back((*it)->getOtherEndpoint(this));
            }
            return adjacents;
        };

        std::vector<Vertex> getSuccessors() {
            std::vector<Vertex> successors;
            for (std::vector<*Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++it) {
                if ((*it)->getStartingEndpoint() == this) {
                    successors.push_back((*it)->getStartingEndpoin());
                }
            }
            return successors;
        }

        std::vector<Vertex> getPredecessors() {
            std::vector<Vertex> predecessors;
            for (std::vector<*Edge>::iterator it = this->edges.begin(); it != this->edges.end(); ++it) {
                if ((*it)->getEndingEndpoint() == this) {
                    predecessors.push_back((*it)->getEndingEndpoint());
                }
            }
            return predecessors;
        }
        int getDegree() {
        };

        bool operator==(const Vertex& vertex) {
            return this->label == vertex.getLabel();
        };
    private:
        std::vector<*Edge> edges; 
        std::string label;
        Graph *graph;
        bool loopback;
}

class Graph {
    private:
        std::set<Edge> edges;
        std::set<Vertex> vertex;
};


int main(int argc, char *argv[]) {

