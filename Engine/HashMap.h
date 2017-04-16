/* 
 * File:   HashMap.h
 * Author: dsbatts
 *
 * Created on April 15, 2017, 5:03 AM
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <functional>
#include <string>
#define DEFAULT_BUCKETS 10
#define BUCKET_THRESHOLD 0.75

template<typename K, typename V> class HashMap
{
public:
    bool deleteItems;

    HashMap()
    {
        this->buckets = static_cast<BucketElement**>(calloc(DEFAULT_BUCKETS, sizeof(BucketElement*)));
        this->size = 0;
        this->numBuckets = DEFAULT_BUCKETS;
        this->maxSize = DEFAULT_BUCKETS * BUCKET_THRESHOLD;
        this->deleteItems = false;
    }

    ~HashMap() { this->cleanUpBuckets(this->buckets, this->numBuckets, this->deleteItems); }

    int getSize() { return this->size; }

    bool containsKey(K* key)
    {
        int hash = this->hashify(key);
        if (this->buckets[hash]) {
                for (BucketElement* b = this->buckets[hash] ; b ; b = b->next) {
                        if (*b->key == *key)
                                return true;
                }
        }
        return false;
    }

    void put(K* key, V* value)
    {
        BucketElement* e = new BucketElement();
        e->key = key;
        e->value = value;
        e->next = NULL;
        this->put(e, this->hashify(e->key));
        this->maintain();
    }

    V* get(K* key)
    {
        int hash = this->hashify(key);
        if (this->buckets[hash] != NULL) {
            BucketElement* b = this->buckets[hash];
            while(b != NULL) {
                if (*b->key == *key)
                    return b->value;
                b = b->next;
            }
        }
        return (V)NULL;
    }
    
    V* remove(K* key)
    {
        int hash = this->hashify(key);
        if (this->buckets[hash] != NULL) {
            BucketElement* prev = NULL;
            BucketElement* b = this->buckets[hash];
            while(b != NULL) {
                if (*b->key == *key) {
                    V* v = b->value;
                    if (prev != NULL)
                        prev->next = b->next;
                    else
                        this->buckets[hash] = b->next;
                    delete b;
                    this->size--;
                    return v;
                }
                prev = b;
                b = b->next;
            }
        }
        return NULL;
    }

private:
    class BucketElement
    {
    public:
        K* key;
        V* value;
        BucketElement* next;
        BucketElement(){}
        ~BucketElement(){}

    };

    BucketElement **buckets;
    int size;
    int maxSize;
    int numBuckets;

    void maintain()
    {
        if (this->size < this->maxSize)
                return;
        int oldNumBuckets = this->numBuckets;
        this->numBuckets *= 2;
        this->maxSize = this->numBuckets * BUCKET_THRESHOLD;
        BucketElement** oldBuckets = this->buckets;
        this->buckets = static_cast<BucketElement**>(calloc(this->numBuckets, sizeof(BucketElement*)));
        this->size = 0;
        for (int i = 0; i < oldNumBuckets; i++) {
            BucketElement* b = oldBuckets[i];
            while (b != NULL) {
                BucketElement* current = b;
                b = b->next;
                current->next = NULL;
                this->put(current, this->hashify(current->key));
            }
        }

        free(static_cast<void*>(oldBuckets));

    }

    int hashify(K* key)
    {
        std::hash<K> hasher;
        int hash = static_cast<int>(hasher(*key)) % this->numBuckets;
        return hash;
    }

    void cleanUpBuckets(BucketElement **bucks, int num, bool doDelete)
    {
        for (int i = 0; i < num; i++) {
            if (bucks[i] != NULL) {
                for (BucketElement* b = bucks[i]; b->next != NULL;) {
                    BucketElement* del = b;
                    b = b->next;
                    delete del;
                }
            }
        }
        free(bucks);
    }

    void put(BucketElement* element, int hash)
    {
        if (this->buckets[hash] == NULL) {
            this->buckets[hash] = element;
            this->size++;
            return;
        }

        BucketElement* prev = NULL;
        BucketElement* b = this->buckets[hash];
        while (b->next != NULL) {
            if (*b->key == *element->key) {
                if (prev != NULL) {
                    prev = element;
                    element->next = b->next;
                    delete b;
                    return;
                }
            }
            prev = b;
            b = b->next;
        }
        b->next = element;
        this->size++;
    }

};




#endif /* HASHMAP_H */

