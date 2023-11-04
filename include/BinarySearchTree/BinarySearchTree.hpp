/*
	MIT License

	Copyright(c) 2023 George Fotopoulos

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files(the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions :

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#pragma once

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <memory>
#include <queue>
#include <utility>

template<typename Key, typename Value>
class BinarySearchTree {
public:
    using Handler = std::function<void(const Key &, Value &)>;

private:
    struct BinarySearchTreeNode {
        BinarySearchTreeNode(const Key &key, const Value &value) : key(key), value(value) {}

        std::shared_ptr<BinarySearchTreeNode> lChild;
        std::shared_ptr<BinarySearchTreeNode> rChild;

        Key key;
        Value value;
    };

    void PreOrderTraversalHelper(std::shared_ptr<BinarySearchTreeNode> root, Handler handler) {
        if (!root) return;
        handler(root->key, root->value);
        PreOrderTraversalHelper(root->lChild, handler);
        PreOrderTraversalHelper(root->rChild, handler);
    }

    void InOrderTraversalHelper(std::shared_ptr<BinarySearchTreeNode> root, Handler handler) {
        if (!root) return;
        InOrderTraversalHelper(root->lChild, handler);
        handler(root->key, root->value);
        InOrderTraversalHelper(root->rChild, handler);
    }

    void PostOrderTraversalHelper(std::shared_ptr<BinarySearchTreeNode> root, Handler handler) {
        if (!root) return;
        PostOrderTraversalHelper(root->lChild, handler);
        PostOrderTraversalHelper(root->rChild, handler);
        handler(root->key, root->value);
    }

    std::shared_ptr<BinarySearchTreeNode> InsertHelper(std::shared_ptr<BinarySearchTreeNode> root, const Key &key, const Value &value) {
        if (!root) return std::make_shared<BinarySearchTreeNode>(key, value);
        if (key == root->key) {
            root->value = value;
        } else if (key < root->key) {
            root->lChild = InsertHelper(root->lChild, key, value);
        } else {
            root->rChild = InsertHelper(root->rChild, key, value);
        }
        return root;
    }

    std::shared_ptr<BinarySearchTreeNode> RemoveHelper(std::shared_ptr<BinarySearchTreeNode> root, const Key &key) {
        if (!root) return nullptr;
        if (key == root->key) {
            if (!root->lChild) {
                return root->rChild;
            } else if (!root->rChild) {
                return root->lChild;
            }
            std::shared_ptr<BinarySearchTreeNode> minRight = MinimumHelper(root->rChild);
            root->key = minRight->key;
            root->value = minRight->value;
            root->rChild = RemoveHelper(root->rChild, minRight->key);
        } else if (key < root->key) {
            root->lChild = RemoveHelper(root->lChild, key);
        } else {
            root->rChild = RemoveHelper(root->rChild, key);
        }
        return root;
    }

    std::shared_ptr<BinarySearchTreeNode> SearchHelper(std::shared_ptr<BinarySearchTreeNode> root, const Key &key) {
        if (!root) return root;
        if (root->key == key) {
            return root;
        } else if (key < root->key) {
            return SearchHelper(root->lChild, key);
        } else {
            return SearchHelper(root->rChild, key);
        }
    }

    std::shared_ptr<BinarySearchTreeNode> MinimumHelper(std::shared_ptr<BinarySearchTreeNode> root) {
        while (root->lChild) root = root->lChild;
        return root;
    }

    std::shared_ptr<BinarySearchTreeNode> MaximumHelper(std::shared_ptr<BinarySearchTreeNode> root) {
        while (root->rChild) root = root->rChild;
        return root;
    }

    int HeightHelper(const std::shared_ptr<BinarySearchTreeNode> root) {
        if (!root) return 0;
        return std::max(HeightHelper(root->lChild), HeightHelper(root->rChild)) + 1;
    }

    int SizeHelper(const std::shared_ptr<BinarySearchTreeNode> root) {
        if (!root) return 0;
        return SizeHelper(root->lChild) + SizeHelper(root->rChild) + 1;
    }

    std::shared_ptr<BinarySearchTreeNode> mRoot;

public:
    BinarySearchTree() = default;

    void PreOrderTraversal(Handler handler) {
        PreOrderTraversalHelper(mRoot, handler);
    }

    void InOrderTraversal(Handler handler) {
        InOrderTraversalHelper(mRoot, handler);
    }

    void PostOrderTraversal(Handler handler) {
        PostOrderTraversalHelper(mRoot, handler);
    }

    void Clear() {
        mRoot.reset();
    }

    void Insert(const Key &key, const Value &value) {
        mRoot = InsertHelper(mRoot, key, value);
    }

    void Remove(const Key &key) {
        mRoot = RemoveHelper(mRoot, key);
    }

    std::shared_ptr<BinarySearchTreeNode> Search(const Key &key) {
        return SearchHelper(mRoot, key);
    }

    std::shared_ptr<BinarySearchTreeNode> Minimum() {
        return MinimumHelper(mRoot);
    }

    std::shared_ptr<BinarySearchTreeNode> Maximum() {
        return MaximumHelper(mRoot);
    }

    int Height() {
        return HeightHelper(mRoot);
    }

    int Size() {
        return SizeHelper(mRoot);
    }
};
