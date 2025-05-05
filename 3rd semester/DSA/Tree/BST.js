
const input = document.querySelector("input");
const btnSubmit = document.querySelector("#submit");
const btnAdd = document.querySelector("#add");
const allList = document.querySelector('.allList');

let list = new Array();
class Point {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
    toString() {
        return this.data;
    }
}

class BST {
    constructor(root = null) {
        this.root = root;
    }

    add(data) {
        if (this.root === null) {
            this.root = new Point(data);
        }
        else {
            const searchTree = function (root) {
                if (root == null) {
                    return;
                }
                else {
                    if (data < root.data) {
                        if (root.left != null) {
                            return searchTree(root.left)
                        }
                        else {
                            root.left = new Point(data);
                            return;
                        }
                    }
                    else if (data > root.data) {
                        if (root.right != null) {
                            return searchTree(root.right)
                        }
                        else {
                            root.right = new Point(data);
                            return;
                        }
                    }
                }
            }
            return searchTree(this.root);
        }
    }
    show(root = this.root) {
        if (root == null) return;
        this.show(root.left);
        list.push(root);
        this.show(root.right);
    }
    find(data) {
        console.log("==========================")
        console.log(`\tFINDING '${data}'`);
        console.log("==========================")

        const search = function (root) {
            if (root == null) {

                return new Point("NOT FOUND").toString();
            }
            else {
                if (data === root.data) return root;
                else if (data < root.data) return search(root.left);
                else if (data > root.data) return search(root.right);
                else {

                    return new Point("NOT FOUND").toString();
                }
            }
        }
        return search(this.root);
    }
    findMax(root = this.root) {
        let current = this.root;
        while (current.right !== null) {
            current = current.right;
        }
        return current;
    }
    findMin(root = this.root) {
        let current = this.root;
        while (current.left !== null) {
            current = current.left;
        }
        return current;
    }
}


const tree = new BST();

tree.add(3)
tree.add(5)
tree.add(2)
tree.add(1)
tree.add(6)
tree.add(4)
list = []
tree.show();

btnSubmit.addEventListener("click", e => {
    e.preventDefault();
    let x = tree.find(Number(input.value))
    if (x) {
        document.getElementById("result").innerText = `${x.toString()}`;
        console.log(x.toString());
    }
})
btnAdd.addEventListener('click', e => {
    e.preventDefault();
    if (input.value) {
        tree.add(Number(input.value));
        input.value = '';
        reload()
    }

})

reload()
function reload() {
    console.group(tree)
    list = new Array();
    tree.show();
    allList.innerHTML = null;
    list.map(ele => {
        const newChild = document.createElement('div')
        const left = document.createElement('div')
        const right = document.createElement('div')

        newChild.className = 'box';
        left.className = 'left';
        right.className = 'right';

        newChild.innerText = `${ele.toString()}: `;
        left.innerText = ele?.left;
        right.innerText = ele?.right;

        if (ele?.left)
            newChild.appendChild(left);
        if (ele?.right)
            newChild.appendChild(right);
        allList.appendChild(newChild);
    })
}