/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package finalproject;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

/**
 *
 * @author Anomaly
 */
@SuppressWarnings("serial")
public final class GraphingCalculator extends JFrame {
    private final int FIELD_WIDTH = 10;
    private final JPanel displayPanel = new JPanel();
    private final JPanel inputPanel = new JPanel();
    private final JPanel functionPanel = new JPanel();
    private final JLabel functionLabel  = new JLabel("Function: ");
    private final JTextField functionField = new JTextField(FIELD_WIDTH);
    private final ActionListener functionFieldListener = new FunctionFieldListener();
    private final JPanel domainPanel = new JPanel();
    private final JLabel domainLabel = new JLabel("Domain: "); 
    private final JTextField domainField = new JTextField(FIELD_WIDTH); 
    private final ActionListener domainFieldListener = new DomainFieldListener();
    private final JPanel rangePanel = new JPanel();
    private final JLabel rangeLabel = new JLabel("Range: ");
    private final JTextField rangeField = new JTextField(FIELD_WIDTH);
    private final ActionListener rangeFieldListener = new RangeFieldListener();
    private final ActionListener radioButtonListener = new RadioButtonListener();
    private final JPanel radioButtonPanel = new JPanel();
    private final JRadioButton polarButton = new JRadioButton("Polar");
    private final JRadioButton cartesianButton = new JRadioButton("Cartesian");
    private final JRadioButton parametricButton  = new JRadioButton("Parametric");
    private final ButtonGroup radioButtonGroup = new ButtonGroup();
    private JButton submitButton;
    
    public GraphingCalculator() {
        
        createInputPanel();
        setLayout(new BorderLayout());
	add(inputPanel, BorderLayout.SOUTH);
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);
        setVisible(true);
    }
    
    public void createInputPanel() 
    { 
        createDomainField();
        createRangeField();
        createFunctionField();
        createRadioButtons();
        
        inputPanel.setLayout(new BorderLayout());
        inputPanel.add(functionPanel, BorderLayout.NORTH);
        inputPanel.add(domainPanel, BorderLayout.WEST);
        inputPanel.add(rangePanel, BorderLayout.EAST);
        inputPanel.add(radioButtonPanel, BorderLayout.SOUTH);
    }
    
    private void createFunctionField()
    {
        functionField.setText("X^2-2X+3");
        
        functionField.addActionListener(functionFieldListener);
        
        functionPanel.add(functionLabel);
        functionPanel.add(functionField);
    }
    
    private void createDomainField()
    {
        domainField.setText("(-10,10)");
        
        domainField.addActionListener(domainFieldListener);
        
        domainPanel.add(domainLabel);
        domainPanel.add(domainField);
    }
    
    private void createRangeField()
    {
        rangeField.setText("(-10,10)");
        
        rangeField.addActionListener(rangeFieldListener);
        
        rangePanel.add(rangeLabel);
        rangePanel.add(rangeField);
    }
    
    public void createRadioButtons()
    {
        polarButton.addActionListener(radioButtonListener);

        cartesianButton.addActionListener(radioButtonListener);

        parametricButton.addActionListener(radioButtonListener);

        radioButtonGroup.add(polarButton);
        radioButtonGroup.add(cartesianButton);
        radioButtonGroup.add(parametricButton);

        radioButtonPanel.add(polarButton);
        radioButtonPanel.add(cartesianButton);
        radioButtonPanel.add(parametricButton);
    }
	
    private class FunctionFieldListener implements ActionListener {
    @Override public void actionPerformed(ActionEvent event) {
                System.out.println(functionField.getText());
    }
    }
    
    private class DomainFieldListener implements ActionListener {
    @Override public void actionPerformed(ActionEvent event) {
                System.out.println(domainField.getText());
    }
    }
    
    private class RangeFieldListener implements ActionListener {
    @Override public void actionPerformed(ActionEvent event) {
                System.out.println(rangeField.getText());
    }
    }
    
    private class RadioButtonListener implements ActionListener {
    @Override public void actionPerformed(ActionEvent event) {
                System.out.println("A Radio Button was pressed.");
    }
    }
}
