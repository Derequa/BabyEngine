#include <iostream>
#include <string>
#include <stdlib.h>
#include "HashMap.h"
#include "HashSet.h"
#include "EngineObject.h"

using namespace std;

int main(int argc, char** argv)
{
	HashMap<string, string> *map = new HashMap<string, string>();
        cout << "Checking size..." << endl;
	cout << map->getSize() << endl;
        cout << "Creating first key/value pair..." << endl;
	string key0 = "Derek";
	string value0 = "Terra";
        cout << "Putting first key/value pair in..." << endl;
	map->put(&key0, &value0);
        cout << "Checking size..." << endl;
	cout << map->getSize() << endl;
        cout << "Checking with contains..." << endl;
        cout << map->containsKey(&key0) << endl;
        cout << "Creating second key/value pair..." << endl;
        string key1 = "Jacob";
	string value1 = "Kellany";
        cout << "Checking invalid key with contains..." << endl;
        cout << map->containsKey(&key1) << endl;
        cout << "Putting second key/value pair in..." << endl;
	map->put(&key1, &value1);
        cout << "Checking with contains..." << endl;
        cout << map->containsKey(&key1) << endl;
        cout << "Checking size..." << endl;
	cout << map->getSize() << endl;
        /*
        HashMap<int, int> map1;
        for (int i = 0 ; i < 1000 ; i++) {
            cout << "Adding #" + std::to_string(i) << endl;
            map1.put(i, i);
            if (map1.getSize() != i + 1) {
                cout << "FAILED TO ADD #" + std::to_string(i) << endl;
                cout << flush;
                return 1;
            }
        }
        for (int i = 0 ; i < 1000 ; i++) {
            cout << "Getting #" + std::to_string(i) << endl;
            int res = map1.get(i);
            if (res != i) {
                cout << "FAILED TO GET #" + std::to_string(i) << endl;
                cout << "GOT #" + std::to_string(res) << endl;
                cout << flush;
                return 1;
            }
        }
        int size = 1000;
        for (int i = 0 ; i < 1000 ; i++) {
            cout << "Removing #" + std::to_string(i) << endl;
            int rem = map1.remove(i);
            size--;
            if (map1.getSize() != size) {
                cout << "FAILED TO Remove #" + std::to_string(i) << endl;
                cout << flush;
                return 1;
            }
            
            if (rem != i) {
                cout << "FAILED TO Remove #" + std::to_string(i) << endl;
                cout << flush;
                return 1;
            }
        }*/
        
        
        HashSet<string> set;
        set.add(&key0);
        set.add(&value0);
        cout << "Checking with contains..." << endl;
        if (!set.contains(&key0)) {
            cout << "FAILED set does not contain: " + key0 << endl;
            cout << flush;
            return 1;
        }
        
        if (!set.contains(&value0)) {
            cout << "FAILED set does not contain: " + value0 << endl;
            cout << flush;
            return 1;
        }
        
        cout << "Checking size..." << endl;
	cout << set.size() << endl;
        cout << "Removing from set..." << endl;
        
        set.remove(&key0);
        set.remove(&value0);
        
        cout << "Checking with contains..." << endl;
        if (set.contains(&key0)) {
            cout << "FAILED set does contain: " + key0 << endl;
            cout << flush;
            return 1;
        }
        
        if (set.contains(&value0)) {
            cout << "FAILED set does contain: " + value0 << endl;
            cout << flush;
            return 1;
        }
        
        cout << "Checking size..." << endl;
	cout << set.size() << endl;
        
        cout << flush;
	return 0;
}