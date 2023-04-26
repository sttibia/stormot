/**
 * Oliveira - A Private source MMORPG server emulator
 */

#ifndef SRC_UTILS_WILDCARDTREE_H_
#define SRC_UTILS_WILDCARDTREE_H_

#include "declarations.hpp"

class WildcardTreeNode {
	public:
		explicit WildcardTreeNode(bool initBreakpoint) :
			breakpoint(initBreakpoint) { }
		WildcardTreeNode(WildcardTreeNode &&other) = default;

		// non-copyable
		WildcardTreeNode(const WildcardTreeNode &) = delete;
		WildcardTreeNode &operator=(const WildcardTreeNode &) = delete;

		WildcardTreeNode* getChild(char ch);
		const WildcardTreeNode* getChild(char ch) const;
		WildcardTreeNode* addChild(char ch, bool breakpoint);

		void insert(const std::string &str);
		void remove(const std::string &str);

		ReturnValue findOne(const std::string &query, std::string &result) const;

	private:
		std::map<char, WildcardTreeNode> children;
		bool breakpoint;
};

#endif // SRC_UTILS_WILDCARDTREE_H_
