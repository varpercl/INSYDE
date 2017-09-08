#include "basictree.h"

core::BasicTree::BasicTree(QWidget *parent) :
	QTreeView(parent)
{
//    Q_INIT_RESOURCE(core_media); //At least in linux, never call this inside user namespace, instead use a wrapper function
	init();
}

core::BasicTree::~BasicTree()
{

}

void core::BasicTree::copyClick()
{

}

void core::BasicTree::cutClick()
{

}

void core::BasicTree::pasteClick()
{

}

void core::BasicTree::contextMenuEvent(QContextMenuEvent *)
{
}

void core::BasicTree::init()
{

}

