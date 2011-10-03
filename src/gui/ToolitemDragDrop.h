/*
 * Xournal++
 *
 * Helper for Toolbar Drag & Drop implementation
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __TOOLBARDRAGDROP_H__
#define __TOOLBARDRAGDROP_H__

#include <gtk/gtk.h>
#include <String.h>

class AbstractToolItem;

enum ToolItemType {
	TOOL_ITEM_SEPARATOR = 0,
	TOOL_ITEM_ITEM,
	TOOL_ITEM_COLOR
};

#define ToolItemDragDropData_Identify 0xFA090201

struct ToolItemDragDropData {
	int identify;
	ToolItemType type;
	int id;
	AbstractToolItem * item;
};


class ToolitemDragDrop {
private:
	ToolitemDragDrop();
	virtual ~ToolitemDragDrop();

public:
	static void attachMetadata(GtkWidget * w, int id, AbstractToolItem * ait);
	static void attachMetadata(GtkWidget * w, int id, String type);

public:
	static ToolItemDragDropData * ToolItemDragDropData_new(AbstractToolItem * item);
	static bool checkToolItemDragDropData(ToolItemDragDropData * d);

private:
	static void toolitemDragBegin(GtkWidget * widget, GdkDragContext * context, void * data);
	static void toolitemDragEnd(GtkWidget * widget, GdkDragContext * context, void * data);
	static void toolitemDragDataGet(GtkWidget * widget, GdkDragContext * context, GtkSelectionData * selection_data,
			guint info, guint time, void * data);

public:
	static void removeFromToolbarForMove(GtkWidget * widget);
};

#endif /* __TOOLBARDRAGDROP_H__ */
