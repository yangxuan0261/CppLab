#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <functional>
#include <cstring>

using namespace std;


namespace lruTest {

    struct SObj {
        SObj(std::string _tex) : mTex(_tex) {}

        std::string mTex;
    };

    typedef std::function<void(std::string, bool)> Filter;
    typedef std::function<void(std::string)> RmCallback;

    class TextureMgr {
    public:
        SObj *AddObj(std::string _str) {
            SObj *ret = nullptr;
            auto iter = mTexMap.find(_str);
            if (iter != mTexMap.end()) {
                ret = iter->second;
                if (mFilter)
                    mFilter(_str, true);
            } else {
                ret = new SObj(_str);
                mTexMap.insert(make_pair(_str, ret));
                if (mFilter)
                    mFilter(_str, false);
            }
            return ret;
        }

        void SetFilter(Filter _f) { mFilter = _f; }

        void Remove(std::string _key) {
            printf("------ remove:%s, trig rm func\n", _key.c_str());
            SObj *dst = mTexMap[_key];
            mTexMap.erase(_key);
            delete dst;
        }

        Filter mFilter;
        std::unordered_map<std::string, SObj *> mTexMap;
    };

    struct SNode {
        SNode() : mStr(""), mPre(nullptr), mNext(nullptr) {}

        ~SNode() {}

        std::string mStr;
        SNode *mPre;
        SNode *mNext;
    };

    static const int gLimit = 5;

    class LruMgr {
    public:
        LruMgr() : mLimit(0) {
            mHead = new SNode();
            mTail = new SNode();
            mHead->mNext = mTail;
            mTail->mPre = mHead;
        }

        ~LruMgr() {
            delete mHead;
            delete mTail;
            //Reset();
            mTail = nullptr;
            mHead = nullptr;


            auto iter = mNodeMap.begin();
            while (iter != mNodeMap.end()) {
                delete iter->second;
                ++iter;
            }
            mNodeMap.clear();

            while (!mRcyQ.empty()) {
                delete mRcyQ.front();
                mRcyQ.pop();
            }
        }

        void Snapshot() {
            selfPrint(mHead);
        }

        void Reset() {
            mHead->mNext = mTail;
            mTail->mPre = mHead;
            auto iter = mNodeMap.begin();
            while (iter != mNodeMap.end()) {
                rcyNode(iter->second);
                ++iter;
            }
            mNodeMap.clear();
        }

        void SetRmCb(RmCallback _f) { mRmCallback = _f; }

        void CaculFunc(std::string _str, bool _isExit) {
            printf("--- str:%s, isExit:%d\n", _str.c_str(), (int) _isExit);
            if (!_isExit) {
                if (mLimit >= gLimit) { //overflow, remove tail pre

                    SNode *node = mTail->mPre; //recycle the node

                    if (mRmCallback)
                        mRmCallback(node->mStr);

                    remove(node);
                    mNodeMap.erase(node->mStr);
                    rcyNode(node);
                    Snapshot();
                }

                SNode *node = getNode();
                mNodeMap.insert(make_pair(_str, node));
                node->mStr = _str;
                insert2Head(node);
                ++mLimit;
            } else {
                SNode *node = mNodeMap[_str];
                remove(node);
                insert2Head(node);
            }
        }

    private:
        void remove(SNode *_dst) {
            _dst->mPre->mNext = _dst->mNext;
            _dst->mNext->mPre = _dst->mPre;
        }

        void insert2Head(SNode *_dst) {
            _dst->mNext = mHead->mNext;
            _dst->mPre = mHead;
            mHead->mNext->mPre = _dst;
            mHead->mNext = _dst;
        }

        void selfPrint(const SNode *_node) {
            if (_node == nullptr)
                return;

            if (strcmp(_node->mStr.c_str(), "") != 0)
                printf("--- snapshot, node:%s\n", _node->mStr.c_str());

            selfPrint(_node->mNext);
        }

        SNode *getNode() {
            SNode *ret = nullptr;
            if (!mRcyQ.empty()) {
                ret = mRcyQ.front();
                mRcyQ.pop();
            } else {
                ret = new SNode();
                printf("-------- new");
            }
            return ret;
        }

        void rcyNode(SNode *_node) {
            printf("-------- rcyNode:%s\n", _node->mStr.c_str());
            mRcyQ.push(_node);
        }

    private:
        int mLimit;
        SNode *mHead;
        SNode *mTail;
        RmCallback mRmCallback;
        std::unordered_map<std::string, SNode *> mNodeMap;
        std::queue<SNode *> mRcyQ;
    };

    void test() {
        LruMgr *lmgr = new LruMgr();
        TextureMgr *tmgr = new TextureMgr();
        tmgr->SetFilter(std::bind(&LruMgr::CaculFunc, lmgr, std::placeholders::_1, std::placeholders::_2));
        lmgr->SetRmCb(std::bind(&TextureMgr::Remove, tmgr, std::placeholders::_1));

        tmgr->AddObj("aaa");
        tmgr->AddObj("bbb");
        tmgr->AddObj("ccc");
        tmgr->AddObj("ddd");
        tmgr->AddObj("eee");
        tmgr->AddObj("fff");
        tmgr->AddObj("bbb");
        tmgr->AddObj("ddd");
        tmgr->AddObj("bbb");

        lmgr->Snapshot();
        delete lmgr;
        lmgr = nullptr;
    }

    void testQueue() {
        std::queue<std::string> tmp;
        tmp.push("aaa");
        tmp.push("bbb");
        tmp.push("ccc");

        printf("--- size:%d\n", tmp.size());
        printf("--- str:%s\n", tmp.front().c_str());
        tmp.pop();
        printf("--- size:%d\n", tmp.size());
        printf("--- str:%s\n", tmp.front().c_str());
        printf("--- empty:%d\n", (int) tmp.empty());
        tmp.pop();
        tmp.pop();
        printf("--- empty:%d\n", (int) tmp.empty());
    }

    void main() {
        test();
        //testQueue();
    }

} // lruTest
