public
void insert(int item)
{

    current = parent = grand = header;

    EMPTY.element = item;

    while (current.element != item)
    {

        great = grand;
        grand = parent;
        parent = current;

        current = item > current.element ? current.right : current.left;

        if (current.left.color == Color.RED && current.right.color == Color.RED)
        {

            reorient(item);
        }
    }

    if (current != EMPTY)
    {
        return;
    }

    current = new Node(item, EMPTY, EMPTY);

    if (item < parent.element)
    {
        parent.left = current;
    }
    else
    {
        parent.right = current;
    }

    reorient(item);
}

protected
void reorient(int item)
{

    current.color = Color.RED;
    current.left.color = Color.BLACK;
    current.right.color = Color.BLACK;

    if (parent.color == Color.RED)
    {

        grand.color = Color.RED;

        if (item < grand.element != item < parent.element)
        {

            parent = rotate(item, grand);
        }

        current = rotate(item, great);

        current.color = Color.BLACK;
    }

    header.right.color = Color.BLACK;
}

private
Node rotate(int item, Node parent)
{

    if (item < parent.element)
    {

        Node node = parent.left;

        Node resultNode = item < node.element ? rotateWithLeftNode(node) : rotateWithRightNode(node);

        parent.left = resultNode;
        return parent.left;
    }
    else
    {
        Node node = parent.right;
        Node resultNode = item < node.element ? rotateWithLeftNode(node) : rotateWithRightNode(node);
        parent.right = resultNode;
        return parent.right;
    }
}

private
Node rotateWithLeftNode(Node element)
{
    Node left = element.left;
    element.left = left.right;
    left.right = element;

    return left;
}

private
Node rotateWithRightNode(Node element)
{
    Node right = element.right;
    element.right = right.left;
    right.left = element;
    return right;
}