#include "stdafx.h"
#include <cstdlib>
#include <climits>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define SEED 16

int randomPrice() {
	return rand() % 811 + 90; //from 90 to 900   
}

int randomAirport(int n) {
	int num = rand() % 50 + 1;
	if (num == n) return randomAirport(n); //no airport flies to itself 
	return num;
}

struct Airport {
	string code;
	// direct flights (neighbors)
	map<string, int> flights;
};

vector<Airport> airports(51);

void init() {
	srand(SEED);
	airports[0].code = "SLC";
	airports[1].code = "DHN";
	airports[2].code = "HSV";
	airports[3].code = "MOB";
	airports[4].code = "MGM";
	airports[5].code = "ANC";
	airports[6].code = "JNU";
	airports[7].code = "FLG";
	airports[8].code = "PHX";
	airports[9].code = "YUM";
	airports[10].code = "FYV";
	airports[11].code = "LIT";
	airports[12].code = "BUR";
	airports[13].code = "LGB";
	airports[14].code = "LAX";
	airports[15].code = "ONT";
	airports[16].code = "PSP";
	airports[17].code = "SMF";
	airports[18].code = "SAN";
	airports[19].code = "SFO";
	airports[20].code = "SJC";
	airports[21].code = "SNA";
	airports[22].code = "ASE";
	airports[23].code = "COS";
	airports[24].code = "DEN";
	airports[25].code = "GJT";
	airports[26].code = "PUB";
	airports[27].code = "BDL";
	airports[28].code = "IAD";
	airports[29].code = "DCA";
	airports[30].code = "DAB";
	airports[31].code = "FLL";
	airports[32].code = "RSW";
	airports[33].code = "JAX";
	airports[34].code = "EYW";
	airports[35].code = "MIA";
	airports[36].code = "MCO";
	airports[37].code = "PNS";
	airports[38].code = "PIE";
	airports[39].code = "SRQ";
	airports[40].code = "TPA";
	airports[41].code = "PBI";
	airports[42].code = "PFN";
	airports[43].code = "ATL";
	airports[44].code = "AGS";
	airports[45].code = "SAV";
	airports[46].code = "ITO";
	airports[47].code = "HNL";
	airports[48].code = "OGG";
	airports[49].code = "KOA";
	airports[50].code = "LIH";

	for (int i = 1; i<51; i++) {
		//from SLC to all others
		airports[0].flights.emplace(airports[i].code, randomPrice());
		//from all others to SLC
		airports[i].flights.emplace(airports[0].code, randomPrice());

		//up to 20 flights from other to other
		for (int j = 0; j<20; j++) {
			airports[i].flights.emplace(airports[randomAirport(i)].code, randomPrice());
		}
	}

}

void displayAirports() {
	for (auto& airport : airports) {
		cout << "Flight from " << airport.code << endl;
		for (auto& flight : airport.flights) {
			cout << "  to " << flight.first << " $" << flight.second << endl;
		}
	}
}

int compareCaseInsensitive(char a, char b) {
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int compareCaseInsensitive(string sA, string sB) {
	unsigned i = 0;
	char a, b;
	while (i < sA.length() && i < sB.length()) {
		a = sA[i];
		b = sB[i];
		int result = compareCaseInsensitive(a, b);
		if (result != 0) return result;
		i++;
	}

	return 0;
}

bool airportComparator(Airport a, Airport b) {
	string sA = a.code, sB = b.code;
	int result = compareCaseInsensitive(sA, sB);
	return result < 0;
}

map<string, Airport*> codeToAirport;
map<string, int> codeToIndex;
map<int, string> indexToCode;

// Number of vertices in the graph
#define SIZE 51

void dijkstra(int graph[SIZE][SIZE], int src) {
	int dist[SIZE];
	bool processed[SIZE];

	for (int i = 0; i < SIZE; i++)
		dist[i] = INT_MAX, processed[i] = false;

	// Distance to source is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < SIZE - 1; count++) {
		// Pick the minimum distance vertex
		int min = INT_MAX, u;

		for (int v = 0; v < SIZE; v++) {
			if (processed[v] == false && dist[v] <= min) {
				min = dist[v];
				u = v;
			}
		}

		// Mark the picked vertex as processed
		processed[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < SIZE; v++) {
			// Update dist[v] only if is not in processed,
			// there is an edge from u to v, 
			// and total weight of path from src -> v through u is < dist[v]
			int alt = dist[u] + graph[u][v];

			if (!processed[v] && graph[u][v] && dist[u] != INT_MAX &&  alt < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}

	cout << "Found flight from " << indexToCode[src] << " to" << endl;
	for (int i = 0; i < SIZE; i++)
		if (i != src)	cout << "\t\t" << indexToCode[i] << " for $" << dist[i] << endl;
}

int main() {
	init();
	sort(airports.begin(), airports.end(), airportComparator);
	
	// let's loop once to fill in translation tables
	for (int i = 0; i < SIZE; i++) {
		codeToAirport.emplace(airports[i].code, &airports[i]);
		codeToIndex.emplace(airports[i].code, i);
		indexToCode.emplace(i, airports[i].code);
	}

	// now lets build a graph
	int graph[SIZE][SIZE];
	for (auto& airport : airports) {
		int i = codeToIndex[airport.code];

		for (auto& neighbor : airports) {
			int j = codeToIndex[neighbor.code];

			if (airport.flights.count(neighbor.code) == 1)
				graph[i][j] = airport.flights[neighbor.code];
			else
				graph[i][j] = 0;
		}
	}

	// then run the dijkstra function for each airport
	for (auto& airport : airports) {
		dijkstra(graph, codeToIndex[airport.code]);
	}
}