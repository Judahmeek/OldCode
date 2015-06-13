/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package three_buttons;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author malehray
 */
public class ThreeButtons {

    public static void main(String[] args) {
        
        final int Nbuttons = 20;
        
        final JButton[] buttons = new JButton[Nbuttons];
        for (int k = 0; k < Nbuttons; k++) {
            buttons[k] = new JButton("Button " + (k + 1));
        }
        
        final JLabel label = new JLabel("No buttons have been pressed.");
        
        JPanel panel = new JPanel();
        for (int k = 0; k < Nbuttons; k++) {
            panel.add(buttons[k]);
        }
        panel.add(label);
        
        class MyListener implements ActionListener {
            @Override public void actionPerformed(ActionEvent event) {
                for (int k = 0; k < Nbuttons; k++) {
                    if (event.getSource() == buttons[k]) {
                        label.setText("Button " + (k+1) + " was pressed.");
                    }
                }
            }
        }
        
        ActionListener listener = new MyListener();
        for (int k = 0; k < Nbuttons; k++) {
            buttons[k].addActionListener(listener);
        }
        
        JFrame frame = new JFrame();
        frame.setSize(400,400);
        frame.setTitle(Nbuttons + " Buttons");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setVisible(true);
        
        
    }
}
